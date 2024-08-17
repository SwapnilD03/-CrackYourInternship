class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int ans=0;
        int n=matrix.size();
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                pq.push(matrix[i][j]);
            }
        }
        
        int c=1;

        while(!pq.empty() && c<=k){
            ans=pq.top();
            c++;
            pq.pop();
        }

        return ans;        
    }
};
