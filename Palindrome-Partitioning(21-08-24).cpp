class Solution {
public:
    bool isPalin(string s,int left,int right){
        while(left<right){
            if(s[left]!=s[right])
            return false;

            left++;right--;
        }

        return true;
    }
    void solve(int index,string s,vector<vector<string>> &ans,vector<string> &partition){
        if(index>=s.size()){
            ans.push_back(partition);
            return;
        }

        for(int i=index;i<s.size();i++){
            if(isPalin(s,index,i)){
                partition.push_back(s.substr(index,i-index+1));
                solve(i+1,s,ans,partition);
                partition.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> partition;

        solve(0,s,ans,partition);
        return ans;
    }
};
