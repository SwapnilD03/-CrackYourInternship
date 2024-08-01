class Solution {
  public:
    bool isSafe(int xnew,int ynew,int n,vector<vector<int>> &mat,vector<vector<bool>> &visited){
        if((xnew>=0 && xnew<n) && (ynew>=0 && ynew<n) && !visited[xnew][ynew] && mat[xnew][ynew]==1){
            return true;
        }
        else{
            return false;
        }
    }
    void solve(int x,int y,vector<vector<int>> &mat,vector<vector<bool>> &visited,vector<string>&ans,int n,string path){
        if(x==n-1 && y==n-1){
            ans.push_back(path);
            return;
        }
        
        if(isSafe(x+1,y,n,mat,visited)){
            visited[x][y]=1;
            solve(x+1,y,mat,visited,ans,n,path+'D');
        }
        
        if(isSafe(x,y-1,n,mat,visited)){
            visited[x][y]=1;
            solve(x,y-1,mat,visited,ans,n,path+'L');
        }
        
        if(isSafe(x,y+1,n,mat,visited)){
            visited[x][y]=1;
            solve(x,y+1,mat,visited,ans,n,path+'R');
        }
        
        if(isSafe(x-1,y,n,mat,visited)){
            visited[x][y]=1;
            solve(x-1,y,mat,visited,ans,n,path+'U');
        }
        
        visited[x][y]=0;
    }
    
    vector<string> findPath(vector<vector<int>> &mat) {
                
        vector<string> ans;
        int n=mat.size();
        vector<vector<bool>> visited(n,vector<bool>(n,0));
        string path="";
        if(mat[0][0]==0){
            return ans;
        }
        solve(0,0,mat,visited,ans,n,path);
        
        return ans;
    }
};


