class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
    int mini=INT_MAX;
        sort(a.begin(),a.end());
        for(int i=0;i+m-1<n;i++){
            if(a[i+m-1]-a[i]<mini){
                mini=a[i+m-1]-a[i];
            }
        }
        return mini;
    }   
};
