class Solution {
public:
    void dfs(vector<vector<int>> &adj,vector<bool>&visited,int src){
        visited[src]=true;
        for(auto neighbour:adj[src]){
            if(!visited[neighbour]){
                dfs(adj,visited,neighbour);
                }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1) return -1;

        vector<vector<int>> adj(n);
        for(int i=0;i<connections.size();i++){
            int u=connections[i][0];
            int v=connections[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool>visited(n,false);
        int components=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(adj,visited,i);
                components++;
            }
        }

        return components-1;

    }
};
