class Solution{
  public:
    bool solve(int sum,int n,vector<int> &visited,int currSum,int a[],int k){
        if(k==1) return 1;
        
        if(currSum>sum) return 0;
        
        if(currSum==sum) return solve(sum,n,visited,0,a,k-1);
        
        for(int i=0;i<n;i++){
            if(!visited[i]){
                visited[i]=1;
                if(solve(sum,n,visited,currSum+a[i],a,k)){
                    return 1;
                }
                visited[i]=0;
            }
        }
        return 0;
    }
    
    bool isKPartitionPossible(int a[], int n, int k)
    {
         int sum=0;
         for(int i=0;i<n;i++){
             sum+=a[i];
         }
         
         if(k>n || sum%k!=0) return 0;
         
         vector<int> visited(n,0);
         sum/=k;
         return solve(sum,n,visited,0,a,k);
    }
};
