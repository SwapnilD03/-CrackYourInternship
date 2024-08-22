class Solution {
public:
    
    int solve(int i, int j, string s, string t,vector<vector<int>> &dp) {
      if(j >= t.size()) {
        return 1;
      }
      if(i>=s.size()) {
        return 0;
      }
      if(dp[i][j] != -1) {
        return dp[i][j];
      }
      int res = solve(i + 1, j, s, t,dp);
      if(s[i] == t[j]) {
        res += solve(i + 1, j + 1, s, t,dp);
      }
      return dp[i][j] = res;
    }
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.size()+1,vector<int>(t.size(),-1));
        return solve(0, 0, s, t,dp);
    }
};
