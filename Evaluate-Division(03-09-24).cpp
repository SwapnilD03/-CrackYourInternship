class Solution {
public:
    void dfs(unordered_map<string,vector<pair<string,double>>>&adj,string src,string dest,unordered_set<string> &visited,double prod,double &ans){
        if(visited.find(src)!=visited.end()) return ;

        visited.insert(src);

        if(src==dest){
            ans=prod;
            return;
        }

        for(auto nbr:adj[src]){
           string v=nbr.first;
           double val=nbr.second;
           dfs(adj,v,dest,visited,prod*val,ans);
        }
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n=equations.size();

        unordered_map<string,vector<pair<string,double>>> adj;

        for(int i=0;i<n;i++){
            string u=equations[i][0];
            string v=equations[i][1];

            adj[u].push_back(make_pair(v,values[i]));
            adj[v].push_back(make_pair(u,1.0/values[i]));
        }

        vector<double> res;
      
        for(auto q:queries){
            string src=q[0];
            string dest=q[1];

            double ans=-1.0;

            double prod=1.0;

            if(adj.find(src)!=adj.end()){
                unordered_set<string> visited;
                dfs(adj,src,dest,visited,prod,ans);
            }

            res.push_back(ans);
        }
        return res;
    }
};
