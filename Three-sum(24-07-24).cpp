class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>> res;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
        int l=i+1;int r=nums.size()-1;
        while(l<r){
            int sum=nums[i]+nums[l]+nums[r];
            if(sum>0){
                r=r-1;
            }
            else if(sum<0){
                l=l+1;
            }
            else{
                res.insert({nums[i],nums[l],nums[r]});
                l++;r--;
            }
         }
        }
        for(auto it:res){
            ans.push_back(it);
        }
        return ans;
    }
};
