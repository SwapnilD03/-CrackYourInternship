class Solution {
public:
    void bfs(vector<vector<char>>& grid,int i,int j,int r,int c,vector<vector<int>> &visited){
        queue<pair<int,int>> q;

        q.push({i,j});
        visited[i][j]=1;

        while(!q.empty()){
            pair<int,int> p=q.front();
            q.pop();
            int row=p.first,col=p.second;

            if(col-1>=0 && grid[row][col-1]=='1' && !visited[row][col-1]){
                q.push({row,col-1});
               visited[row][col-1]=1;
            }

            if(row+1<r && grid[row+1][col]=='1' && !visited[row+1][col]){
               q.push({row+1,col});
               visited[row+1][col]=1;
            }

            if(col+1<c && grid[row][col+1]=='1' && !visited[row][col+1]){
                q.push({row,col+1});
               visited[row][col+1]=1;
            }

             if(row-1>=0 && grid[row-1][col]=='1' && !visited[row-1][col]){
                q.push({row-1,col});
               visited[row-1][col]=1;
            }

             

        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        vector<vector<int>> visited(r,vector<int>(c,0));
        int ans=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]=='1' && !visited[i][j]){
                    bfs(grid,i,j,r,c,visited);
                    ans++;
                }
            }
        }
        return ans;
    }
};
