class Solution {
public:
    int solve(int curr,int len,vector<int>nums, int k,vector<vector<int>> &dp){
        if(curr==nums.size()){
            return 0;
        }
        if(dp[curr][len]!=-1){
            return dp[curr][len];
        }
        int newLen=len+1+nums[curr];
        int a=INT_MAX;
        if(newLen<=k){
            a=solve(curr+1,newLen,nums,k,dp);
        }
        int b=solve(curr+1,nums[curr],nums,k,dp)+pow(k-len,2);
        
        return dp[curr][len]=min(a,b);
    }
    int solveWordWrap(vector<int>nums, int k) 
    { 
        vector<vector<int>> dp(nums.size(),vector<int>(k+1,-1));
        return solve(1,nums[0],nums,k,dp);
    } 
};
