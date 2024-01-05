
class Solution {
  public:
    int singleElement(int arr[] ,int N) {
        // code here
        
        int result=0;
        for(int k=0;k<=31;k++){
            int temp =(1<<k);
            int oneCount=0;
            
            for(int i=0;i<N;i++){
                if(arr[i]&temp){
                    oneCount++;
                }
                
            }
            if(oneCount%3==1){
                result =(result|temp);
            }
        }
        return  result;
    }
};
