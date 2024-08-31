class Solution{
  public:
  bool sumZero(vector<int>& temp,int *starti,int *endj,int n){
      unordered_map<int,int>preSum;
      int sum=0;
      int maxLen=0;
      
      for(int i=0;i<n;i++){
          sum+=temp[i];
          if(temp[i]==0 && maxLen==0){
              *starti=i;
              *endj=i;
              maxLen=1;
          }
          if(sum==0){
              if(maxLen<i+1){
                  *starti=0;
                  *endj=i;
              }
              maxLen=i+1;
          }
          if(preSum.find(sum)!=preSum.end()){
              int old=maxLen;
              maxLen=max(maxLen,i-preSum[sum]);
              
              if(old<maxLen){
                  *endj=i;
                  *starti=preSum[sum]+1;
                  
              }
          }
          else{
              preSum[sum]=i;
          }
      }
      return maxLen!=0;
  }
  vector<vector<int>> sumZeroMatrix(vector<vector<int>> a){
      int n=a.size();
      int m=a[0].size();
      
      int startR=0,endR=0,startC=0,endC=0;
      int sum;
      int up,down;
      int maxL=INT_MIN;
      
      for(int l=0;l<m;l++){
          vector<int> temp(n,0);
          for(int r=l;r<m;r++){
              
              for(int i=0;i<n;i++){
                  temp[i]+=a[i][r];
              }
              
              bool sum=sumZero(temp,&up,&down,n);
              int ele=(down-up+1)*(r-l+1);
             
              if(sum && ele>maxL){
                  maxL=ele;
                  startR=up;
                  endR=down;
                  startC=l;
                  endC=r;
              }
          }
      }
      
      vector<vector<int>> ans;
      for(int i=startR;i<=endR;i++){
          vector<int> res;
          for(int j=startC;j<=endC;j++){
              res.push_back(a[i][j]);
          }
          ans.push_back(res);
      }
      return ans;
  }
};
