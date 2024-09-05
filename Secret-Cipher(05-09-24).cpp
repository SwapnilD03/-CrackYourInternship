class Solution{
    public:
    vector<int> helper(string s){
        int n=s.length();
       vector<int> lps(n,0);
       int l=0,i=1;
       while(i<n){
           if(s[i]==s[l]){
               l++;
               lps[i]=l;
               i++;
           }
           else{
               if(l==0){
                   lps[l]=0;
                   i++;
               }
               else{
                   l=lps[l-1];
               }
           }
       }
       return lps;
    }
    string compress(string s)
    {
        vector<int> a=helper(s);
        
        int n=s.length();
        
        string ans="";
        int i= n-1;
        
        while(i>0){
            if(i%2==0){
                ans+=s[i];
                i--;
                continue;
            }
            bool f=false;
            int suffix=a[i];
            int substring=i+1;
            
            if(suffix*2>=substring){
                if(substring%(substring-suffix)==0){
                    if((substring/(substring-suffix))%2==0){
                        f=true;
                    }
                }
            }
            
            if(f==true){
                ans+="*";
                i=(i/2)+1;
            }
            
            else{
                ans+=s[i];
            }
            i--;
        }
        
        reverse(ans.begin(),ans.end());
        return s[0]+ans;
        
    }
};
