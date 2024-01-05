//Approach-1 (Recursion + Memoization)
//T.C : O(n)
//S.C : O(n)
class Solution{
	public:
	int t[100001][2];
	int M = 1e9 + 7;
	
	int space    = 0;
	int building = 1;
	    
	int solve(int n, int status) {
	    if(n == 0)
	        return 1; //All done. Found one way
	    
	    if(t[n][status] != -1) 
	        return t[n][status];
	    
	    if(status == building) 
	        return t[n][status] = solve(n - 1, space) % M;
	    
	    else
	        return t[n][status] = (solve(n - 1, building) % M + solve(n - 1, space) % M) % M;
	        
	       
	   return -1; //Yaha kabhi nahi aaega flow
	}
	
	int TotalWays(int N) {
	    memset(t, -1, sizeof(t));
	    
	    long long x = (solve(N - 1, building) % M + solve(N - 1, space) % M) % M;
	    
	    return (x * x) % M;
	}
};
