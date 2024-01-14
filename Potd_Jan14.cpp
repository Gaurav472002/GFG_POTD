class Solution
{   
    public:
    vector<int> repeatedRows(vector<vector<int>> &matrix, int M, int N) 
    { 
        // Your code here
        vector<int>ans;
        set<string>s;
        for(int i=0;i<M;i++){
            string temp="";
            for(int j=0;j<N;j++){
                temp+= to_string(matrix[i][j]);
            }
            if(s.find(temp)!=s.end())ans.push_back(i);
            s.insert(temp);
        }
        return ans;
      
    } 
};
