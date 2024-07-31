class Solution {
public:
    bool backspaceCompare(string s, string t) {
       stack<char>s1;
       stack<char>s2;

       for(int i=0;i<s.length();i++){
        if(s[i]=='#'){
          if(!s1.empty())
            s1.pop();
        }
        else{
            s1.push(s[i]);
        }
       }

       for(int i=0;i<t.length();i++){
        if(t[i]=='#'){
            if(!s2.empty())
            s2.pop();
        }
        else{
            s2.push(t[i]);
        }
       } 
       string a="";
       while(!s1.empty()) 
       {
        a=a+s1.top();
        s1.pop();

        }
        string b="";
        while(!s2.empty()) 
       {
        b=b+s2.top();
        s2.pop();
       }
        return a==b;
    }
};
