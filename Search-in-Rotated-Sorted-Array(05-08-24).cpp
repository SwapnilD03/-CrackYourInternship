class Solution {
public:
    int search(vector<int>& nums, int target) {
        unordered_map<int,int> pos;
        for(int i=0;i<nums.size();i++){
            pos[nums[i]]=i;
        }

        sort(nums.begin(),nums.end());
        int l=0;
        int r=nums.size()-1;
        while(l<=r){
            int mid=l+(r-l)/2;

            if(target>nums[mid]){
                l=mid+1;
            }
            else if(target<nums[mid]){
                r=mid-1;
            }
            else{
                return pos[nums[mid]];

            }
        }
        return -1;
    }
};
