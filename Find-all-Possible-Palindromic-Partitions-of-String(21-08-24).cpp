class Solution {
  public:
    bool isPalin(string S,int i,int j){
        while(i<j){
            if(S[i]!=S[j])
            return false;
            
            i++;j--;
        }
        
        return true;
    }
    void dfs(int i,string S,vector<vector<string>> &ans,vector<string> &partition){
        if(i>=S.size()){
            ans.push_back(partition);
            return;
        }
        
        for(int j=i;j<S.size();j++){
            if(isPalin(S,i,j)){
                partition.push_back(S.substr(i,j-i+1));
                dfs(j+1,S,ans,partition);
                partition.pop_back();
            }
        }
    }
    vector<vector<string>> allPalindromicPerms(string S) {
        vector<vector<string>> ans;
        vector<string> partition;
        
        dfs(0,S,ans,partition);
        
        return ans;
    }
};
