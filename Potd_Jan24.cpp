class Solution {
  public:
  
  
  void dfs(int node,vector<bool>&vis,vector<int>adj[]){
      vis[node]=1;
      for(auto nbr: adj[node]){
          if(!vis[nbr]){
              dfs(nbr,vis,adj);  // simple bfs traversak
          }
      }
  }
  
  
  
    int isTree(int n, int m, vector<vector<int>> &edges) {
        // code her
        
        
        if(n-m!=1)return 0; // in a tree the difference between node and edges is 1 so if n-m !=1 this is not a tree
        
        vector<int>adj[n]; // form the adjacency list for the graph
        
        for(auto edge: edges){   //  as the graph is undirected consider both edges
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<bool>vis(n,0); // create a vis array to perform dfs to  keep track of visited nodes
        
        dfs(0,vis,adj); // perfrom dfs on the graph
        
        for(int i=0;i<n;i++){
            if(vis[i]==0)return 0 ; // If we were not able to traverse each node then this is not a tree  there must be a cycle present
        }
        return 1; // if all the nodes were traversed then this graph is a tree
    }
};
