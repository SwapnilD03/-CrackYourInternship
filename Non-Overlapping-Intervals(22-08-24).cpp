class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b){
        return a[0]<b[0];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);

        int ans=0;
        int prevEnd=intervals[0][1];

        for(auto i:intervals){
            if(i[0]>=prevEnd){
                prevEnd=i[1];
            }
            else{
                ans++;prevEnd=min(i[1],prevEnd);
            }
        }
        return ans-1;
    }
};
