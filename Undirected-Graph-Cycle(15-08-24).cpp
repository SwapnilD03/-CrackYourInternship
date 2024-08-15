class Solution {
  public:
    bool isCyclicBfs(int src,vector<int> adj[],unordered_map<int,bool> &visited){
        unordered_map<int,int> parent;
        
        parent[src]=-1;
        
        visited[src]=true;
        queue<int> q;
        q.push(src);
        
        while(!q.empty()){
            int frontNode=q.front();
            q.pop();
            
            for(auto neighbour:adj[frontNode]){
                if(visited[neighbour] && neighbour!=parent[frontNode]){
                    return true;
                }
                
                else if(!visited[neighbour]){
                    q.push(neighbour);
                    visited[neighbour]=true;
                    parent[neighbour]=frontNode;
                }
            }
            
        }
        
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        unordered_map<int,bool> visited;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                bool ans=isCyclicBfs(i,adj,visited);
                
                if(ans){
                    return true;
                }
                
            }
        }
        
        return false;
    }
};
