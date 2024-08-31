class Solution{
    public:
    
    int wordBreak(string A, vector<string> &B) {
        vector<bool> dp(A.size()+1,0);
        
        dp[A.size()]=1;
        
        for(int i=A.size()-1;i>=0;i--){
            for(auto w:B){
                if(i+w.size()<=A.size() && A.substr(i,w.size())==w){
                    dp[i]=dp[i+w.size()];
                }
                if(dp[i]) break;
            }
        }
        return dp[0];
    }
};
