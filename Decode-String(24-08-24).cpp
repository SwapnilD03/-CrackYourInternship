class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(s[i]!=']'){
                st.push(s[i]);
                continue;
            }
            string tmp="";
            while(!st.empty() && st.top()!='['){
               tmp=st.top()+tmp;
               st.pop();
            }

            st.pop();
            string k="";
            string str="";
            while(!st.empty() && isdigit(st.top())){
                k=st.top()+k;
                st.pop();
            }
            int count=stoi(k);
            for(int j=1;j<=count;j++){
                str+=tmp;
            }

            for(auto c:str){
                st.push(c);
            }
        }

        string ans="";
        while(!st.empty()){
            ans=st.top()+ans;
            st.pop();
        }
        return ans;
    }
};
