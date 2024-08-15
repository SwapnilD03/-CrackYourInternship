class Solution {
  public:
    int longestCommonSubstr(string str1, string str2) {
        vector<vector<int>> dp(str1.length()+1,vector<int>(str2.length()+1,0));
        int maxi=0;
        for(int i=1;i<=str1.length();i++){
            int curr=0;
            for(int j=1;j<=str2.length();j++){
                if(str1[i-1]==str2[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                    if(maxi<dp[i][j]){
                        maxi=dp[i][j];
                    }
                }
            }
        }
        return maxi;
    }
};
