class Solution {
public:

    int res,nonObstacles;
    void backtrack(vector<vector<int>>& grid,int i,int j,int m,int n,int count){
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j]==-1){
            return;
        }

        if(grid[i][j]==2){
            if(count==nonObstacles)
            res++;
            return;
        }
        grid[i][j]=-1;

        backtrack(grid,i,j+1,m,n,count+1);
        backtrack(grid,i,j-1,m,n,count+1);
        backtrack(grid,i+1,j,m,n,count+1);
        backtrack(grid,i-1,j,m,n,count+1);

        grid[i][j]=0;


    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        res=0;
        int count=0;
        int m=grid.size();
        int n=grid[0].size();

        int start_x=0,start_y=0;
        nonObstacles=0;

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==0){
                    nonObstacles++;
                }
                if(grid[i][j]==1){
                    start_x=i;start_y=j;
                }
            }

        }
        nonObstacles+=1;
        backtrack(grid,start_x,start_y,m,n,count);

        return res;

    }
};
