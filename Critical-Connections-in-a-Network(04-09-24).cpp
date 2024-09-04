class Solution {
public:
    void dfs(int node,int parent,int timer,vector<int>&discovery,vector<int>&low,vector<vector<int>> &res,unordered_map<int,list<int>> &adj,unordered_map<int,bool> &visited){
        visited[node]=true;

        discovery[node]=low[node]=timer++;

        for(auto nbr:adj[node]){
            if(nbr==parent){
                continue;
            }
            if(!visited[nbr]){
                dfs(nbr,node,timer,discovery,low,res,adj,visited);
                low[node]=min(low[node],low[nbr]);
                if(low[nbr]>discovery[node]){
                    vector<int> ans;
                    ans.push_back(node);
                    ans.push_back(nbr);
                    res.push_back(ans);
                }
            }
            else{
                low[node]=min(low[node],discovery[nbr]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        unordered_map<int,list<int>> adj;

        for(int i=0;i<connections.size();i++){
            int u=connections[i][0];
            int v=connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int timer=0;
        vector<int>discovery(n);
        vector<int> low(n);
        int parent=-1;
        unordered_map<int,bool> visited;

        for(int i=0;i<n;i++){
            discovery[i]=-1;
            low[i]=-1;
        }
       vector<vector<int>> res;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,parent,timer,discovery,low,res,adj,visited);
            }
        }

        return res;
    }
};
