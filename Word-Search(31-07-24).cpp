class Solution {
public:

    bool isPossible(int i,int j,vector<vector<char>>& board, string word,int k,int m,int n,vector<vector<bool>> &visited){
        if(k==word.length()){
            return true;
        }

        if(i<0 || i>=m || j<0 || j>=n || visited[i][j]==true || board[i][j]!=word[k]){
            return false;
        }

        visited[i][j]=true;

        bool down=isPossible(i+1,j,board,word,k+1,m,n,visited);
        bool up=isPossible(i-1,j,board,word,k+1,m,n,visited);
        bool right=isPossible(i,j+1,board,word,k+1,m,n,visited);
        bool left=isPossible(i,j-1,board,word,k+1,m,n,visited);
        visited[i][j]=false;
        return down||up||right||left;
        
    }
    bool exist(vector<vector<char>>& board, string word) {

        int m=board.size();
        int n=board[0].size();
        int l=word.length();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
               
                if(isPossible(i,j,board,word,0,m,n,visited)){
                    return true;
                }
                
            }
        }
        return false;
    }
};
