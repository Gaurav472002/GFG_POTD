class Solution
{
    public:
    
    
    int solve(Node * root,int& ans){
        if(!root)return 0;
        
        int left =solve(root->left,ans);
        int right =solve(root->right,ans);
        ans+= abs(left)+ abs(right);
        
        return (left+right+root->key)-1;
    }
    
    int distributeCandy(Node* root)
    {
        //code here
        int ans=0;
        solve(root,ans);
        return ans;
    }
};
