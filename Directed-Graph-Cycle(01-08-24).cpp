class Solution {
  public:
    bool checkCyclicDirected(int node,vector<int> adj[],unordered_map<int,bool> &visited,unordered_map<int,bool> &dfsVisited){
        visited[node]=true;
        dfsVisited[node]=true;
        
        for(auto neighbour:adj[node]){
            if(!visited[neighbour]){
                bool check=checkCyclicDirected(neighbour,adj,visited,dfsVisited);
                if(check){
                    return true;
                }
            }
            
            else if(dfsVisited[neighbour]){
                return true;
            }
        }
        dfsVisited[node]=false;
        return false;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        
        unordered_map<int,bool> visited;
        unordered_map<int,bool> dfsVisited;
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                bool ans=checkCyclicDirected(i,adj,visited,dfsVisited);
                if(ans){
                    return true;
                }
            }
        }
        
        return false;
        
    }
};
