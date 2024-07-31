class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        int mini=INT_MAX;
        string miniEle="";
        for(int i=0;i<strs.size();i++){
            if(strs[i].length()<mini){
                mini=strs[i].length();
                miniEle=strs[i];
            }
        }

        ans=miniEle;
        for(int i=0;i<strs.size();i++){
            int ind=0;string ele=strs[i];
            for(int j=0;j<mini;j++){
                if(ele[j]!=miniEle[j]){
                    break;
                }
                else{
                    ind++;
                }
            }
            string common=ele.substr(0,ind);
            if(common.length()<ans.length()){
                ans=common;
            }
        }

        return ans;
    }
};
