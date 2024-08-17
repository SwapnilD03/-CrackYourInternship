class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n);
        dp[0]=1;
        int p1=0,p2=0,p3=0;

        for(int i=1;i<n;i++){
            int twoMult=dp[p1]*2;
            int threeMult=dp[p2]*3;
            int fiveMult=dp[p3]*5;

            dp[i]=min(twoMult,min(threeMult,fiveMult));

            if(dp[i]==twoMult) p1++;
            if(dp[i]==threeMult) p2++;
            if(dp[i]==fiveMult) p3++;
        }

        return dp[n-1];
    }
};
