class Solution {
public:
    int solve(int ind,int prevInd,vector<int>& nums,int n,vector<vector<int>> &dp){
        if(ind==n){
            return 0;
        }
        if(dp[ind][prevInd+1]!=-1){
            return dp[ind][prevInd+1];
        }
        int len=0+solve(ind+1,prevInd,nums,n,dp);
        if(prevInd==-1 || nums[ind]>nums[prevInd]){
           len=max(len,1+solve(ind+1,ind,nums,n,dp));
        }
        return dp[ind][prevInd+1]=len;
       }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return solve(0,-1,nums,n,dp);
    }
};
