class Solution {
public:
    void combinations(int start,int n,int k,vector<int>&res,vector<vector<int>> &ans){
         if(res.size()==k){
            ans.push_back(res);
            return;
         }
         for(int i=start;i<=n;i++){
             res.push_back(i);
             combinations(i+1,n,k,res,ans);
             res.pop_back();     
         }
         
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>res;
        vector<vector<int>> ans;
        combinations(1,n,k,res,ans);
        return ans;
    }
};
