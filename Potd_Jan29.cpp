class Solution{
	public:
	
	int t[101][901];
	
	    int solve(string str,int n,int index,int sum){
	        
	        if(index==n)return 1;
	        if(t[index][sum]!=-1)return t[index][sum];
	        int ans=0;
	        int curr=0;
	        for(int i=index;i<n;i++){
	            curr+=str[i]-'0';
	            if(curr>=sum){
	                ans+=solve(str,n,i+1,curr);
	            }
	        }
	        return t[index][sum]=ans;
	    }
	
	
	
	int TotalCount(string str){
	    // Code here
	    
	   int n =str.length();
	   memset(t,-1,sizeof(t));
	   return solve(str,n,0,0);
	}

};
