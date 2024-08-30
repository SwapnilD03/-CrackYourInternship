class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n=grid.size();
        deque<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    q.push_back({i,j});
                }
            }
        }

        int ans=-1;
        vector<vector<int>> directions={{0,1},{0,-1},{1,0},{-1,0}};
        while(!q.empty()){
            pair<int,int> p=q.front();
            int r=p.first,c=p.second;
            q.pop_front();
            ans=grid[r][c];
            for(auto it:directions){
                int newR=r+it[0],newC=c+it[1];
                if(newR>=0 && newR<n && newC>=0 && newC<n && grid[newR][newC]==0){
                     q.push_back({newR,newC});
                     grid[newR][newC]=grid[r][c]+1;
                } 
               
            }

        }

        return(ans>1)? ans-1:-1;

    }
};
