class Solution {
public:

//  this will give TLE if we dont do i*i
// the prime factors can be found only if we traverse till it square root

//  Time Complexity: O( b*log(b) )
//  Space Complexity: O( b*log(b) )


    int solve(int n){
        int ans= 0;
        for(int i=2;i*i<=n;i++){
            while(n%i==0){
                n/=i;
                ans++;
                
            }
        }
        if(n!=1){  // this is for numbers whose primes factors are 1. They will never reach till 1.
        // For example 11 will never get divided so it will not enter in the while loop
        // so to consider 1 as prime factor we are manually adding it.
            ans++;
        }
        return ans;
    }

	int sumOfPowers(int a, int b){
	    // Code here
	    int ans=0;
	    for(int i=a;i<=b;i++){
	        ans+= solve(i);
	    }
	    return ans;
	}
};
