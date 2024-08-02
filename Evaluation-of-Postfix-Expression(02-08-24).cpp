class Solution
{
    public:
    int evaluatePostfix(string S)
    {
        stack<int> st;
        
        for(int i=0;i<S.length();i++){
            if(isdigit(S[i])){
                st.push(S[i]-'0');
            }
                else{
                    int a=st.top();st.pop();
                    int b=st.top();st.pop();
                    if(S[i]=='+'){
                        st.push(b+a);
                    }
                    if(S[i]=='-'){
                        st.push(b-a);
                    }
                    if(S[i]=='*'){
                        st.push(b*a);
                    }
                    if(S[i]=='/'){
                        st.push(b/a);
                    }
                }
            }
        
        return st.top();
    }
};
