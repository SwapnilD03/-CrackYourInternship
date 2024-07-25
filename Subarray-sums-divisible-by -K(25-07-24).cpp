class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int count=0;
        int prefixSum=0;

        unordered_map<int,int> mp;

        mp[0]=1;
        int n=nums.size();
        for(int i=0;i<n;i++){
            prefixSum+=nums[i];

            int rem=prefixSum%k;
            if(rem<0){
                rem+=k;
            }
            if(mp.find(rem)!=mp.end()){
            count+=mp[rem];
            }
            mp[rem]++;
        }

        return count;

    }
};
