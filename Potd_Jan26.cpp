class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    
    static bool comp(Item a, Item b){
        double r1 = (double) a.value/a.weight;
        double r2 = (double) b.value/b.weight;
        return r1>r2;
    }
    
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        
        // sort on the bases of value per weight
        
        sort(arr,arr+n,comp);
        
        double final=0.0;
        int currW =0;
        
        for(int i=0;i<n;i++){
            if(currW + arr[i].weight<=W){
                currW+=arr[i].weight;
                final+=arr[i].value; // take the item as whole
            }
            else{
                // take the fraction
                int remain = W- currW;
                final+= (arr[i].value/(double)arr[i].weight)* (double)remain;
                break;
            }
        }
        return final;
    }
        
};
