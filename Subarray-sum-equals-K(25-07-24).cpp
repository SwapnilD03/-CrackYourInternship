class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count=0;int n=nums.size();
        int prefixSum=0;
        unordered_map<int,int> mp;
        mp[0]=1;
        for(int i=0;i<n;i++){
            prefixSum+=nums[i];
            int remove=prefixSum-k;
            count+=mp[remove];
            mp[prefixSum]++;
        }
        return count;
    }
};
