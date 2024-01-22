class Solution
{
    public:
    
    vector<vector<int>>result;
    
    void solve(Node * root,int sum,int &ans,vector<int>&temp){
        if(!root)return;
        ans+=root->key;
        temp.push_back(root->key);
        if(ans==sum){
            result.push_back(temp);
        }
        
        solve(root->left,sum,ans,temp);
        solve(root->right,sum,ans,temp);
        ans-=root->key;
        temp.pop_back();
        return ;
        
    }
    
    vector<vector<int>> printPaths(Node *root, int sum)
    {
        //code here
        vector<int>temp;
        int ans=0;
        solve(root,sum,ans,temp);
        return result;
    }
};
