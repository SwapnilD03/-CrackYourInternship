class Compare{
        public:
        static bool operator()(vector<int>a,vector<int>b){
            return sqrt(pow(a[0],2)+pow(a[1],2)) > sqrt(pow(b[0],2)+pow(b[1],2));
        }
    };
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>,vector<vector<int>>,Compare> pq;

        for(auto i:points){
            pq.push(i);
        }

        vector<vector<int>> ans;
        int i=1;
        while(!pq.empty() && i<=k){
            ans.push_back(pq.top());
            i++;
            pq.pop();
        }

        return ans;
    }
};
