class Solution {
public:
    int solve(int i,int j,int count,vector<int>& boxes,vector<vector<vector<int>>> &dp){
        if(i>j) return 0;
        if(dp[i][j][count]!=-1)  return  dp[i][j][count];
        
        int ans=pow(count+1,2)+solve(i+1,j,0,boxes,dp);
        for(int k=i+1;k<=j;k++){
            if(boxes[k]==boxes[i])
            ans=max(ans,solve(k,j,count+1,boxes,dp)+solve(i+1,k-1,0,boxes,dp));
        }
        return dp[i][j][count]=ans;
    }
    int removeBoxes(vector<int>& boxes) {
        int n=boxes.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(n+1,-1)));
        return solve(0,n-1,0,boxes,dp);
    }
};
