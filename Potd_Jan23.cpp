//User function Template for C++

class Solution
{
  public:
    vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites) 
    {
        //code here
        vector<int>adj[n];
        vector<int>topo;
        vector<int>indegree(n);
        
        for(auto it: prerequisites){
            int a =it[0];
            int b =it[1];
            adj[b].push_back(a);
        }
        
        for(int i=0;i<n;i++){
            for(auto j: adj[i]){
                indegree[j]++;
            }
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int node =q.front();
            q.pop();
            topo.push_back(node);
            
            for(auto nbr: adj[node]){
                indegree[nbr]--;
                if(indegree[nbr]==0){
                    q.push(nbr);
                }
            }
        }
        return topo.size()==n?topo:vector<int>();
    }
};
