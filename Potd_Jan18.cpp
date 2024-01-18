class Solution{
    public:
    int min_sprinklers(int gallery[], int n)
    {
        // code here
        vector<pair<int,int>>range;
        for(int i=0;i<n;i++){
            if(gallery[i]!=-1){
                int left = max(0,i-gallery[i]);
                int right = min(n-1,gallery[i]+i);
                range.push_back({left,right});
            }
        }
        
        sort(range.begin(),range.end()); // sort the ranges
        
        
        int taps =0;
        int i=0;
        int target =0;
        
        while(target<n){
                int maxright=-1;
                while(i<range.size()){
                    if(range[i].first<=target){
                        maxright =max(maxright,range[i].second);
                        i++;
                    }
                    else{
                        break;
                    }
                }
                if(maxright<target){
                    return -1;
                }
                taps++;
                target = maxright+1;
        }
        return taps;
        
    }
};
