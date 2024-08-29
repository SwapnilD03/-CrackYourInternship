class Solution {
public:
    void dfs(vector<vector<int>>& stones,int ind,vector<bool> &visited){
        visited[ind]=true;

        for(int i=0;i<stones.size();i++){
            int r=stones[ind][0],c=stones[ind][1];
            if(!visited[i] && (stones[i][0]==r || stones[i][1]==c))
            dfs(stones,i,visited);
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        vector<bool> visited(n,false);

        int grps=0;

        for(int i=0;i<n;i++){
            if(visited[i])
            continue;
            
            dfs(stones,i,visited);
            grps++;
        }

        return n-grps;
    }
};
