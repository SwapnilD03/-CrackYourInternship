class Solution{
    public:
    int minDiff=INT_MAX;
    void solve(vector<int>& arr, int n,int idx,vector<int> &s1,vector<int> &s2,vector<vector<int>>& ans,int sum1,int sum2){
        
        if(idx==n){
            int diff=abs(sum1-sum2);
            if(diff<minDiff){
                minDiff=diff;
                ans.clear();
                ans.push_back(s1);
                ans.push_back(s2);
            }
        }
        if(s1.size()<(n+1)/2){
            s1.push_back(arr[idx]);
            solve(arr,n,idx+1,s1,s2,ans,sum1+arr[idx],sum2);
            s1.pop_back();
        }
        
        if(s2.size()<(n+1)/2){
            s2.push_back(arr[idx]);
            solve(arr,n,idx+1,s1,s2,ans,sum1,sum2+arr[idx]);
            s2.pop_back();
        }
    }
     vector<vector<int>> minDifference(vector<int>& arr, int n){
        vector<vector<int>> ans;
        vector<int> s1;
        vector<int> s2;
        int sum1=0,sum2=0;
        
        int idx=0;
        
        solve(arr,n,idx,s1,s2,ans,sum1,sum2);
        return ans;
    }
};
