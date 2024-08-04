class Solution {
public:
    void solve(int i,vector<int>& nums,vector<vector<int>> &ans,vector<int>& res){
        if(i>=nums.size()){
            ans.push_back(res);
            return;
        }

        //include
        res.push_back(nums[i]);
        solve(i+1,nums,ans,res);
        
        //exclude
        res.pop_back();

        solve(i+1,nums,ans,res);

        
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> res;
        solve(0,nums,ans,res);
        return ans;
    }
};
