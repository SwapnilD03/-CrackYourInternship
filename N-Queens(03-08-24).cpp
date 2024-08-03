class Solution {
public:

    void addSolution(vector<vector<string>> &board,vector<vector<string>> &ans,int n){
        vector<string> temp;
        for(int i=0;i<n;i++){
            string str="";
            for(int j=0;j<n;j++){
               str=str+board[i][j];
            }
            temp.push_back(str);
        }

        ans.push_back(temp);
    }
    bool isSafe(int row,int col,vector<vector<string>> &board,int n){
        int x=row;int y=col;

        while(y>=0){
            if(board[x][y]=="Q")
            return false;
            y--;
        }
        x=row;y=col;
        while(x>=0 && y>=0){
            if(board[x][y]=="Q")
            return false;
            x--;y--;
        }

        x=row;y=col;
        while(x<n && y>=0){
            if(board[x][y]=="Q")
            return false;
            x++;y--;
        }

        return true;
    }
    void solve(int col,vector<vector<string>> &ans,vector<vector<string>> &board,int n){
          if(col==n){
            addSolution(board,ans,n);
            return;
          }

          for(int rows=0;rows<n;rows++){
            if(isSafe(rows,col,board,n)){
                board[rows][col]="Q";
                solve(col+1,ans,board,n);
                board[rows][col]=".";
            }
          }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> board(n,vector<string> (n,"."));
        vector<vector<string>> ans;
        solve(0,ans,board,n);

        return ans;
    }
};
