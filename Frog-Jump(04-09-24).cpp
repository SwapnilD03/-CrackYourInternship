class Solution {
public:
    bool solve(vector<int>& stones,unordered_map<int,int>  &mp,int currIdx,int prevJump,vector<vector<int>> &dp){
        if(currIdx==stones.size()-1) return true;
        if(dp[currIdx][prevJump]!=-1) return dp[currIdx][prevJump];
        bool f=false;
        for(int nextJump=prevJump-1;nextJump<=prevJump+1;nextJump++){
            if(nextJump>0){
                int nextStone=stones[currIdx]+nextJump;
                if(mp.find(nextStone)!=mp.end()){
                    f=f||solve(stones,mp,mp[nextStone],nextJump,dp);
                }
            }
        }

        return dp[currIdx][prevJump]=f;
    }
    bool canCross(vector<int>& stones) {
        int n=stones.size();
        unordered_map<int,int>  mp;
        vector<vector<int>> dp(n,vector<int>(n,-1));
        for(int i=0;i<n;i++){
            mp[stones[i]]=i;
        }

        return solve(stones,mp,0,0,dp);
    }
};
