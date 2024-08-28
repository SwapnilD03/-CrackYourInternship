class Solution {
public:
    int solve(int i,int j,int m,int n,vector<vector<char>>& matrix,int &maxi,vector<vector<int>> &dp){
        if(i>=m || j>=n){
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int right=solve(i,j+1,m,n,matrix,maxi,dp);
        int diagonal=solve(i+1,j+1,m,n,matrix,maxi,dp);
        int down=solve(i+1,j,m,n,matrix,maxi,dp);
        if(matrix[i][j]=='1'){
            dp[i][j]=1+min(right,min(diagonal,down));
            maxi=max(maxi,dp[i][j]);
            return dp[i][j];
        }
        else{
            return 0;
        }
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int maxi=0;
        int m=matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        solve(0,0,m,n,matrix,maxi,dp);
        return maxi*maxi;
    }
};
