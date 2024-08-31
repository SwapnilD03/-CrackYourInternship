class Solution{
    public:
    int dp[101][101];
    int sumfreq(int i,int j,int freq[]){
        int sum=0;
        for(int k=i;k<=j;k++){
            sum+=freq[k];
        }
        return sum;
    }
    int cost(int i,int j,int freq[]){
        if(i>j){
            return 0;
        }
        if(i==j){
            return dp[i][j]=freq[i];
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        int wt=sumfreq(i,j,freq);
        int ans=INT_MAX;
        
        for(int k=i;k<=j;k++){
            int tmp=cost(i,k-1,freq)+cost(k+1,j,freq);
            ans=min(tmp,ans);
        }
        
        return dp[i][j]=ans+wt;
        
    }
    int optimalSearchTree(int keys[], int freq[], int n)
    {
        memset(dp,-1,sizeof(dp));
        return cost(0,n-1,freq);
    }
};
