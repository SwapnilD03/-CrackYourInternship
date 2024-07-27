class Solution {
  public:
    
    void dfsHelper(int src,vector<int> adj[],unordered_map<int,bool> &visited,vector<int> &ans){
        
        if(visited[src]){
            return;
        }
        visited[src]=true;
        ans.push_back(src);
        
        for(auto it:adj[src]){
            if(!visited[it]){
                dfsHelper(it,adj,visited,ans);
            }
        }
        
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        
        vector<int> ans;
        
        unordered_map<int,bool> visited(V);
        for(int i=0;i<V;i++){
            visited[i]=0;
        }
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfsHelper(i,adj,visited,ans);
            }
        }
        return ans;
    }
};
