class Solution {
public:
    int mergeStones(vector<int>& stones, int k) {
        int n=stones.size();

        if((n-k)%(k-1)!=0) return -1;

        vector<vector<int>> dp(n+1,vector<int>(n+1,0));

        vector<int> prefSum(n+1,0);
   
        for(int i=0;i<n;i++){
            prefSum[i+1]=prefSum[i]+stones[i];
        }

        for(int len = k; len <= n; len++) {
            for(int i = 0; i + len <= n; i++) {
                int j = i + len - 1;
                dp[i][j] = INT_MAX;
                for(int m = i; m < j; m += (k - 1)) {
                    dp[i][j] = min(dp[i][j], dp[i][m] + dp[m + 1][j]);
                }
                if((len - 1) % (k - 1) == 0) {
                    dp[i][j] += prefSum[j + 1] - prefSum[i];
                }
            }
        }

        return dp[0][n - 1];
    }
};
