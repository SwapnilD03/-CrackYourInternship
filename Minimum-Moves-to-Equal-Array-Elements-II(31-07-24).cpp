class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        int low=0,high=nums.size();
        int mid=low+(high-low)/2;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans+=abs(nums[mid]-nums[i]);
        }

        return ans;
    }
};
