class Solution {
public:
    int calculate(string s) {
        if(s.length()==0){
            return 0;
        }
        
        long long curr=0;
        stack<int>st;

        char op='+';

        for(int i=0;i<s.length();i++){
            char ch=s[i];

            if(ch>=48 && ch<=57){
                curr=curr*10+ch-'0';
            }

            if(!(ch>=48 && ch<=57) && ch!=' ' || i==s.length()-1){
                if(op=='+'){
                 st.push(curr);
                }
                else if(op=='-'){
                st.push(-curr);
                }
                else if(op=='*'){
                    int val=st.top();
                    st.pop();
                    st.push(val*curr);
                }
                else if(op=='/'){
                    int val=st.top();
                    st.pop();
                    st.push(val/curr);
                }

                curr=0;
                op=ch;

            }
        }

        long long ans=0;

        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }

        return ans;


    }
};
