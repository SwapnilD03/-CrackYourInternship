#include<algorithm>
#include<string>
class Solution {
public:
    string reverseWords(string s) {
        s=" "+s;
        string ans="";
        string rev="";
        for(int i=s.length()-1;i>=0;i--){
            char ch=s[i];
            if(ch!=' '){
                rev=ch+rev;
            }
            else{
                if(rev!=""){
                ans=ans+rev+" ";
                rev="";
                }
            }
        }
        return ans.substr(0,ans.length()-1);
    }
};
