

class Solution
{
    public:
    
    
    void findMax(string str,string &max,int k,int idx){
        
       if(k==0){
           return;
       }
       
       int n=str.length();
       
       char maxi=str[idx];
       for(int i=idx+1;i<n;i++){
           if(maxi<str[i]){
               maxi=str[i];
           }
       }
       
       if(maxi!=str[idx]){
           k--;
       }
       
       for(int i=idx;i<n;i++){
           if(str[i]==maxi){
               swap(str[i],str[idx]);
               if(str.compare(max)>0){
                   max=str;
                }
                
                findMax(str,max,k,idx+1);
                
                swap(str[i],str[idx]);
           }
       }
       
    }
    string findMaximumNum(string str, int k)
    {
       string max=str;
       
       findMax(str,max,k,0);
       
       return max;
    }
};
