class Solution{
    public:
    int ans;
        void helper(int index,int n,vector<pair<int, int>> &edges,unordered_set<int>&st){
            if(index>n){
             for(auto it:edges){
                 if(st.find(it.first)==st.end()&&st.find(it.second)==st.end())
                 return;
             }   
             ans=(st.size()<ans)?st.size():ans;
             return;
            }
            helper(index+1,n,edges,st);
            st.insert(index);
            helper(index+1,n,edges,st);
            st.erase(index);
        }
        int vertexCover(int n, vector<pair<int, int>> &edges) {
                ans=n;
                unordered_set<int>st;
                helper(1,n,edges,st);
                return ans;
            }
};
