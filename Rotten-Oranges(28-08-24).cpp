class Solution 
{
    public:
     
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int fresh=0,time=0;
        deque<pair<int,int>> q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    fresh++;
                }
                if(grid[i][j]==2){
                    q.push_back({i,j});
                }
            }
        }
        vector<vector<int>> directions={{0,1},{0,-1},{1,0},{-1,0}};
        while(!q.empty()  && fresh>0){
            int size=q.size();
            for(int i=0;i<size;i++){
                pair<int,int> p=q.front();
                q.pop_front();
                int r=p.first,c=p.second;
                for(auto d:directions){
                    int row=d[0]+r,col=d[1]+c;
                    if(row<0 || row >=n || col<0 || col>=m || grid[row][col]!=1){
                        continue;
                    }
                    grid[row][col]=2;
                    q.push_back({row,col});
                    fresh--;
                }

            }
            time++;
        }
        return (fresh==0)?time:-1;
    
    }
};
