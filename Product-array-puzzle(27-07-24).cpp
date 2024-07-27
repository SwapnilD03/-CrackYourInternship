class Solution{
  public:
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       long long product=1;
       int countZero=0;
       for(int i=0;i<n;i++) {
           if(nums[i]!=0){
           product*=nums[i];
           }
           else{
               countZero++;
           }
       }      
       
       vector<long long int> ans(n);
       
       for(int i=0;i<n;i++){
           if(nums[i]==0){
               if(countZero==1){
                   ans[i]=product;
               }
               else{
                   ans[i]=0;
               }
           }
           
           else{
               if(countZero>=1){
                   ans[i]=0;
               }
               else{
                   ans[i]=product/nums[i];
               }
               
           }
           
       }
       
       return ans;
    }
};
