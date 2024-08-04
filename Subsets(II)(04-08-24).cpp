class Solution {
public:
    void solve(int i,vector<int>& nums,vector<vector<int>> &ans,vector<int> &res){
       ans.push_back(res);

       for(int j=i;j<nums.size();j++){
        if(j!=i && nums[j]==nums[j-1]){
            continue;
        }
        res.push_back(nums[j]);
        solve(j+1,nums,ans,res);
        res.pop_back();
       }

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> res;
        sort(nums.begin(),nums.end());

        solve(0,nums,ans,res);

        return ans;
    }
};
