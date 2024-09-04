class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        set<pair<int,int>> visited;
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        vector<int> starting={grid[0][0],0,0};
        pq.push(starting);
        vector<vector<int>> directions={{0,1},{0,-1},{1,0},{-1,0}};

        visited.insert({0,0});

        while(!pq.empty()){
            vector<int> vec=pq.top();
            pq.pop();
            int t=vec[0],r=vec[1],c=vec[2];
            visited.insert({r,c});

            if(r==n-1 && c==n-1){
                return t;
            }
            for(auto d:directions){
                int neiRow=r+d[0],neiCol=c+d[1];
                if(neiRow<0 || neiRow>=n || neiCol<0 || neiCol>=n || visited.find({neiRow,neiCol})!=visited.end()){
                    continue;
                }
                visited.insert({neiRow,neiCol});
                vector<int> tmp;
                tmp.push_back(max(t,grid[neiRow][neiCol]));
                tmp.push_back(neiRow);
                tmp.push_back(neiCol);
                pq.push(tmp);
            }
        }
        return 0;
    }
};
