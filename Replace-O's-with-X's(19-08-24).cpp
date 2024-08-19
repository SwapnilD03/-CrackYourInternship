class Solution{
public:
    int N,M;
    void floodFill(vector<vector<char>> &ans,int x,int y,char prev,char next){
        if(x<0 || x>=N || y<0 || y>=M )
        return;
        
        if(ans[x][y]!=prev)
        return;
        
        ans[x][y]=next;
        
        floodFill(ans,x+1,y,prev,next);
        floodFill(ans,x-1,y,prev,next);
        floodFill(ans,x,y+1,prev,next);
        floodFill(ans,x,y-1,prev,next);
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        N=n;
        M=m;
        vector<vector<char>> ans=mat;
        
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(ans[i][j]=='O')
                    ans[i][j]='-';
            }
        }
        
        
        for(int i=0;i<n;i++){
            if(ans[i][0]=='-')
                floodFill(ans,i,0,'-','O');
        }
        
        for(int i=0;i<n;i++){
            if(ans[i][m-1]=='-')
                floodFill(ans,i,m-1,'-','O');
        }
        
        for(int j=0;j<m;j++){
            if(ans[0][j]=='-')
                floodFill(ans,0,j,'-','O');
        }
        
        for(int j=0;j<m;j++){
            if(ans[n-1][j]=='-')
                floodFill(ans,n-1,j,'-','O');
        }
        
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(ans[i][j]=='-')
                    ans[i][j]='X';
            }
        }
        
        return ans;
    }
};
