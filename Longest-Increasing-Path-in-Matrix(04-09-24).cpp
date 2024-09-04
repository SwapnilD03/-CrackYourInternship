class Solution {
public:
    int dfs(int r,int c,int prevVal,vector<vector<int>>& matrix,vector<vector<int>> &dp){
        if(r<0 || r>=matrix.size() || c<0 || c>=matrix[0].size() || matrix[r][c]<=prevVal){
           return 0;
        }

        if(dp[r][c]!=-1) return dp[r][c];

        int res=1;

        res=max(res,1+dfs(r+1,c,matrix[r][c],matrix,dp));
        res=max(res,1+dfs(r-1,c,matrix[r][c],matrix,dp));
        res=max(res,1+dfs(r,c+1,matrix[r][c],matrix,dp));
        res=max(res,1+dfs(r,c-1,matrix[r][c],matrix,dp));

        dp[r][c]=res;

        return res;

    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int maxi=0;
        vector<vector<int>> dp(m,vector<int>(n,-1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
               maxi=max(maxi,dfs(i,j,-1,matrix,dp));
            }
        }
        return maxi;
    }
};
