class Solution {
public:
    

    int solveMem(vector<pair<int,int>>&strs,int i, int m,int n, vector<vector<vector<int>>>&dp)
    {
       
        if(i>=strs.size())
        return 0;

        if(dp[i][m][n]!=-1)
        {  
    
            return dp[i][m][n];        
        }

         int zeroes = strs[i].first;
         int ones = strs[i].second;
         int include=0,exclude=0;

         if(m-zeroes >=0 && n-ones>=0)
         {
            include = 1 + solveMem(strs,i+1,m-zeroes,n-ones,dp);
         }
         exclude = solveMem(strs,i+1,m,n,dp);
         
         dp[i][m][n] = max(include,exclude);


         return dp[i][m][n] ;

    }

    
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        
        vector<pair<int,int>>str1; 
        for(auto s:strs)
        {
            int ones=0,zeros=0;
            for(auto ch:s)
            {
                if(ch=='1')ones++;
                if(ch=='0')zeros++;
            }
            str1.push_back({zeros,ones});
        }

        int i=0;

        vector<vector<vector<int>>>dp(str1.size()+1,vector<vector<int>>(m+1,vector<int>(n+1,-1)));

        int ans = solveMem(str1,i,m,n,dp);
       
        return ans;


    }
};
