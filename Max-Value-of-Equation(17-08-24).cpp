class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>> pq; 
        pq.push({points[0][1]-points[0][0],points[0][0]});
        int maxi=INT_MIN;int sum;

        for(int i=1;i<points.size();i++){
            sum=points[i][1]+points[i][0];

            while(!pq.empty() && points[i][0]-pq.top()[1]>k){            
                pq.pop();
            }

            if(!pq.empty()){
                maxi=max(maxi,sum+pq.top()[0]);
            
            }
            pq.push({points[i][1]-points[i][0],points[i][0]});
        }
        
        return maxi;
    }
};
