class Solution {
  public:
   int getMin(vector<int> a){
       int pos=0;
       int mini=INT_MAX;
       
       for(int i=0;i<a.size();i++){
           if(a[i]<mini){
               mini=a[i];
               pos=i;
           }
       }
       return pos;
   }
   
   int getMax(vector<int> a){
       int pos=0;
       int maxi=INT_MIN;
       
       for(int i=0;i<a.size();i++){
           if(a[i]>maxi){
               maxi=a[i];
               pos=i;
           }
       }
       return pos;
   }
   
    vector<vector<int>> minCashFlow(vector<vector<int>> &transaction, int n) {
        vector<int> netAmt(n,0);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                netAmt[i]+=transaction[j][i]-transaction[i][j];
            }
        }
        
        int cntZero=0;
        
        for(int i=0;i<n;i++){
                if(netAmt[i]==0)
                cntZero++;
        }
        
        vector<vector<int>> ans(n,vector<int>(n,0));
        
        while(cntZero!=n){
            int minAmtIdx=getMin(netAmt);
            int maxAmtIdx=getMax(netAmt);
            
            if(netAmt[maxAmtIdx]>abs(netAmt[minAmtIdx])){
                ans[minAmtIdx][maxAmtIdx]=abs(netAmt[minAmtIdx]);
                netAmt[maxAmtIdx]=netAmt[maxAmtIdx]-abs(netAmt[minAmtIdx]);
                netAmt[minAmtIdx]=0;
            }
            
            else if(netAmt[maxAmtIdx]<abs(netAmt[minAmtIdx])){
                ans[minAmtIdx][maxAmtIdx]=abs(netAmt[maxAmtIdx]);
                netAmt[minAmtIdx]=netAmt[minAmtIdx]+netAmt[maxAmtIdx];
                netAmt[maxAmtIdx]=0;
                
            }
            
            else{
                ans[minAmtIdx][maxAmtIdx]=abs(netAmt[minAmtIdx]);
                netAmt[maxAmtIdx]=0;
                netAmt[minAmtIdx]=0;
                cntZero++;
            }
            
            cntZero++;
        }
        
        return ans;
    }
};
