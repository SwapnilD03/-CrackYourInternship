class Solution{
	public:
	int solve(vector<int>nums, int amount){
	    vector<int> dp(amount+1,INT_MAX);
	    dp[0]=0;
	    for(int i=1;i<=amount;i++){
	        for(int j=0;j<nums.size();j++){
	            if(i-nums[j]>=0 && dp[i-nums[j]]!=INT_MAX)
	            dp[i]=min(dp[i],1+dp[i-nums[j]]);
	        }
	       
	    }
	    return dp[amount];
	    
	}
	int MinCoin(vector<int>nums, int amount)
	{
	  
	    int ans=solve(nums,amount);
	    return (ans==INT_MAX)?-1:ans;
	}
};
