class Solution {
public:
    void dfs1(int node, int parent, vector<int> adj[], vector<int>& count, vector<int>& res) {
        for (int neighbor : adj[node]) {
            if (neighbor == parent) continue;
            dfs1(neighbor, node, adj, count, res);
            count[node] += count[neighbor];
            res[node] += res[neighbor] + count[neighbor];
        }
        count[node] += 1; 
    }

    void dfs2(int node, int parent, vector<int> adj[], vector<int>& count, vector<int>& res, int n) {
        for (int neighbor : adj[node]) {
            if (neighbor == parent) continue;
            res[neighbor] = res[node] - count[neighbor] + (n - count[neighbor]);
            dfs2(neighbor, node, adj, count, res, n);
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int> res(n, 0), count(n, 0);
        vector<int> adj[n];

       
        for (int i=0;i<edges.size();i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        
        dfs1(0, -1, adj, count, res);

        
        dfs2(0, -1, adj, count, res, n);

        return res;
    }
};
