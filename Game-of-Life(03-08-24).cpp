class Solution {
public:

    int countLivingNeighbours(int i,int j,int m, int n,vector<vector<int>>& board){
        int ans=0;
                if(i-1 >=0 && j-1>=0){
                   ans+=board[i-1][j-1];
                    
                }
                if(i-1 >=0 && j+1 <n){
                      ans+=board[i-1][j+1];
                        
                }
                if(j-1 >= 0){
                    ans+=board[i][j-1];
                   
                }
                if( j+1<n ){
                    ans+=board[i][j+1];
                   
                }
                if(i+1<m && j+1<n){
                    ans+=board[i+1][j+1];
                   
                }
                if(i+1<m){
                    ans+=board[i+1][j];
                  
                }
                if(i+1<m && j-1>=0){
                   ans+=board[i+1][j-1];
                }
                if(i-1>=0){
                   ans+=board[i-1][j];
                }
                return ans;
    }
    void gameOfLife(vector<vector<int>>& board) {

        int m=board.size();
        int n=board[0].size();
        vector<vector<int>>newBoard(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int count=countLivingNeighbours(i,j,m,n,board);
                if(board[i][j]==1){
                if(count<2){
                   newBoard[i][j]=0;
                }
                if(count==2|| count==3){
                    newBoard[i][j]=1;
                }
                if(count>3){
                   newBoard[i][j]=0;
                }
                }
                else{
                    if(count==3){
                        newBoard[i][j]=1;
                    }
                }
            }
        }
        board=newBoard;
    }
};
