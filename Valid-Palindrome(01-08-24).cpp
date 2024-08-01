class Solution {
public:
    bool isPalindrome(string s){
        int i=0,j=s.length()-1;
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;j--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        if(isPalindrome(s)){
            return true;
        }

        int i=0,j=s.length()-1;
        while(i<=j){
            if(s[i]==s[j]){
                i++;j--;
            }
            else{
                return isPalindrome(s.substr(0,i)+s.substr(i+1)) || isPalindrome(s.substr(0,j)+s.substr(j+1));
            }
        }

        return true;
    }
};
