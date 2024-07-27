class Solution {
  public:
    
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
    
        queue<int> q;
    
        vector<int> ans;
        
        unordered_map<int,bool> visited(V);
        
        for(int i=0;i<V;i++){
            visited[i]=false;
        }
      
        visited[0]=true;
        q.push(0);
        
        while(!q.empty()){
            int frontNode=q.front();
            q.pop();
            ans.push_back(frontNode);
            
            for(auto it:adj[frontNode]){
                if(!visited[it]){
                    q.push(it);
                    visited[it]=true;
                }
            }
        }
        
        return ans;
    }
};
