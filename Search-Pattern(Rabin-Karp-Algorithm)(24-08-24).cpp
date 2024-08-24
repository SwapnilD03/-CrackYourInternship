class Solution
{
    public:
        vector <int> search(string pattern, string text)
        {
           vector<int> ans;
           
           int MOD=101;
           int RADIX=26;
           
           int m=pattern.size();
           int n=text.size();
           
           int i,j;
           
           int hashp=0,hasht=0;
           int h=1;
           
           for(int i=0;i<m-1;i++){
               h=(h*RADIX)%MOD;
           }
           
           for(int i=0;i<m;i++){
               hashp=(RADIX*hashp + pattern[i])%MOD;
               hasht=(RADIX*hasht + text[i])%MOD;
           }
           
           for(int i=0;i<=n-m;i++){
               if(hasht==hashp){
                   
                   for(j=0;j<m;j++){
                       if(text[i+j]!=pattern[j]){
                       break;
                       }
                   }
                   
                   if(j==m){
                       ans.push_back(i+1);
                   }
                   
               }
                   
                   if(i<n-m){
                       hasht=(RADIX*(hasht - text[i]*h) + text[i+m])%MOD;
                       if(hasht<0){
                           hasht+=MOD;
                       }
                   }
               
           }
           
           return ans;
           
        }
     
};
