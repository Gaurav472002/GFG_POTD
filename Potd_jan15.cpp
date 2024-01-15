class Solution{
    public:
    
        
    int t[1002][1002];
    
    int solve(int n,int total,vector<int>&cost,int i){
        if(i==n)return 0;
        if(total<=0)return 0;
        if(t[i][total]!=-1)return t[i][total];
        
        int takeCourse =0;
        int NotTakeCourse=0;
        if(total>=cost[i]){
            takeCourse = 1+ solve(n,total-cost[i]/10.0,cost,i+1);
        }
        NotTakeCourse = solve(n,total,cost,i+1);
        return t[i][total]=max(takeCourse,NotTakeCourse);
    }
    
    int max_courses(int n, int total, vector<int> &cost)
    {
        //Code Here
        memset(t,-1,sizeof(t));
        return solve(n,total,cost,0);
    }
};
