class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string curr="";
        path=path+'/';
        for(int i=0;i<path.length();i++){
            if(path[i]=='/'){
               if(curr==".."){
                if(!st.empty()) st.pop();
               }
               else if(curr!="" && curr!="."){
                st.push(curr);
               }
               curr="";
            }
            else{
                curr=curr+path[i];
            }
        }
        string ans="";
        while(!st.empty()){
            ans=st.top()+"/"+ans;
            st.pop();
        }
        ans=ans.substr(0,ans.length()-1);

        return "/"+ans;

    }
};
