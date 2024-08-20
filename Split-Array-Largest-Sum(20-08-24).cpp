class Solution {
public:
    bool canSplit(int largest,vector<int>& nums,int k){
        int subArr=0;
        int currSum=0;

        for(auto n:nums){
            currSum+=n;
              if(currSum>largest){
                subArr++;
                currSum=n;
              }
        }

        if(subArr+1<=k){
            return true;
        }
        return false;
    }
    int splitArray(vector<int>& nums, int k) {
        int l=nums[0],r=0;

        for(auto n:nums){
            l=max(l,n);
            r+=n;
        }

        int ans=r;

        while(l<=r){
        int mid=l+(r-l)/2;
           if(canSplit(mid,nums,k)){
            ans=mid;
            r=mid-1;
           }
           else{
            l=mid+1;
           }
        }   
        return ans;  
    
    }
};
