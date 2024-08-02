class Solution {
public:
    void solve(int pos,vector<int>& candidates, int target,vector<int> &res,vector<vector<int>> &ans){
        if(target==0){
            ans.push_back(res);
        }
        if(target<=0){
            return;
        }
        int prev=-1;
        for(int i=pos;i<candidates.size();i++){
            if(candidates[i]==prev){
                continue;
            }
                res.push_back(candidates[i]);
                solve(i+1,candidates,target-candidates[i],res,ans);
                res.pop_back();
                prev=candidates[i];   
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> res;
        solve(0,candidates,target,res,ans);
        return ans;
    }
};
