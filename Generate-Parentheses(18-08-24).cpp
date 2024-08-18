class Solution {
public:
    void Generate(int n,int closedCount,int openCount,vector<string> &ans,string res){
        if(closedCount==n && openCount==n){
            ans.push_back(res);
            return;
        }
        if(openCount<n){
            res=res+'(';
            Generate(n,closedCount,openCount+1,ans,res);
            res=res.substr(0,res.length()-1);
        }

        if(closedCount<openCount){
            res=res+')';
            Generate(n,closedCount+1,openCount,ans,res);
            res=res.substr(0,res.length());
        }
        
    }
    vector<string> generateParenthesis(int n) {
        int closedCount=0;
        int openCount=0;
        vector<string> ans;
        string res="";
        Generate(n,closedCount,openCount,ans,res);

        return ans;
    }
};
