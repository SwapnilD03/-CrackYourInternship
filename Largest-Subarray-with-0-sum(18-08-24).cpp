class Solution {
  public:
    int maxLen(vector<int>& arr, int n) {
        int maxi=0;
        int sum=0;
        map<int,int>mp;
        
        for(int i=0;i<n;i++){
            sum+=arr[i];
            
            if(sum==0){
                maxi=i+1;
            }
            
            if(mp.find(sum)!=mp.end()){
                maxi=max(maxi,i-mp[sum]);
            }
            
            else{
                mp[sum]=i;
            }
        }
        return maxi;
        
    }
};
