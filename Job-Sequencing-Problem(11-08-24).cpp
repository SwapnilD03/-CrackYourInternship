class Solution 
{
    static bool compare(Job a,Job b){
        return (a.profit > b.profit);
    }
    public:
    
    
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr,arr+n,compare);
        
        int maxi=arr[0].dead;
        
        for(int i=0;i<n;i++){
            maxi=max(maxi,arr[i].dead);
        }
        
        int countJobs=0,jobProfit=0;
        
        int slot[maxi+1];
        
        for(int i=0;i<=maxi;i++){
            slot[i]=-1;
        }
        
        for(int i=0;i<n;i++){
            for(int j=arr[i].dead;j>0;j--){
                if(slot[j]==-1){
                    slot[j]=i;
                    countJobs++;
                    jobProfit+=arr[i].profit;
                    break;
                }
            }
        }
        
        return {countJobs,jobProfit};
    } 
};
