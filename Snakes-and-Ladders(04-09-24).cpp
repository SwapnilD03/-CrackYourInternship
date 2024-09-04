class Solution {
public:
    pair<int,int> intToPos(int n,int length){
        int r=(n-1)/length;
        int c=(n-1)%length;
        if(r%2!=0){
            c=length-1-c;
        }

        return {r,c};
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        int length=board.size();
        reverse(board.begin(),board.end());
        
        deque<pair<int,int>> q;
        q.push_back({1,0});
        set<int> visited;

        while(!q.empty()){
            pair<int,int>p=q.front();
            q.pop_front();
            int sq=p.first,moves=p.second;

            for(int i=1;i<=6;i++){
                int nextSq=sq+i;
                pair<int,int> coordinate=intToPos(nextSq,length);
                int r=coordinate.first,c=coordinate.second;

                if(board[r][c]!=-1){
                    nextSq=board[r][c];
                }
                if(nextSq==length*length){
                    return moves+1;
                }

                if(visited.find(nextSq)==visited.end()){
                    visited.insert(nextSq);
                    q.push_back({nextSq,moves+1});
                }
            }
        }

        return -1;
    }
};
