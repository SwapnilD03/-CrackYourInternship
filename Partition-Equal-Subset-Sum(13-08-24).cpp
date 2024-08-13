class Solution{
public:
    bool solve(int i,int N,int arr[],int currSum,int totalSum,vector<vector<int>> &dp){
        if(i==N){
            if(currSum==totalSum-currSum){
                return true;
            }
            else{
                currSum=0;
                return false;
            }
        }
        
        if(dp[i][currSum]!=-1){
            return dp[i][currSum];
        }
        
        bool incl=solve(i+1,N,arr,currSum+arr[i],totalSum,dp);
        bool excl=solve(i+1,N,arr,currSum,totalSum,dp);
        
        return dp[i][currSum]=incl||excl;
    }
    int equalPartition(int N, int arr[])
    {
        int currSum=0;
        int totalSum=0;
        for(int i=0;i<N;i++){
            totalSum+=arr[i];
        }
        
        vector<vector<int>> dp(N,vector<int>(totalSum+1,-1));
        bool ans=solve(0,N,arr,currSum,totalSum,dp);
        
        return ans;
    }
};
