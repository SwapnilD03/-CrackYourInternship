class Solution {
public:
int solve(int mask,int ind,int n,vector<vector<int>>&cost,vector<vector<int>>&dp){
    if(mask==(1<<n)-1) return cost[ind][0];
    
    if(dp[mask][ind]!=-1) return dp[mask][ind];
    
    int ans=INT_MAX;
    
    for(int i=0;i<n;i++){
        if((mask&(1<<i))==0)
        ans=min(ans,cost[ind][i]+solve((mask | (1<<i)),i,n,cost,dp));
    }
    
     dp[mask][ind]=ans;
     return ans;
}
int total_cost(vector<vector<int>>cost){
    int n=cost.size();
    vector<vector<int>> dp((1<<n)+5,vector<int>(n,-1));
    
    
    return solve(1,0,n,cost,dp);
}
};
