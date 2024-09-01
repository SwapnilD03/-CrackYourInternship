class Solution {
public:
    int knightDialer(int n) {
        if(n==1) return 10;
        const int mod=1000000007;
        vector<vector<int>> jumps={{4,6},{6,8},{7,9},{4,8},{3,9,0},{},{1,7,0},{2,6},{1,3},{2,4}};


        vector<int> dp(10,1);

        for(int i=0;i<n-1;i++){
            vector<int> nextdp(10,0);
            for(int n=0;n<10;n++){
                for(auto j:jumps[n]){
                    nextdp[j]=(nextdp[j]+dp[n])%mod;
                }
            }
            dp=nextdp;
        }
        int ans=0;

        for(auto n:dp){
            ans=(ans+n)%mod;
        }

        return ans;
    }
};
