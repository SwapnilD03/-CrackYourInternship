class Solution
{
    public:
    
    int missingNumber(int arr[], int n) 
    { 
       
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            if(mp.find(arr[i])!=mp.end()){
                mp[arr[i]]++;
            }
            else{
                mp[arr[i]]=1;
            }
        }
        
        int ans=1;
        while(true){
            if(mp.find(ans)==mp.end()){
                break;
            }
            ans++;
        }
        return ans;
    } 
};
