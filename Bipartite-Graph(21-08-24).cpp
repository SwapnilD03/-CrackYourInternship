class Solution {
private:
    bool check(int start,int V,vector<int>&color,vector<int>adj[]){
        queue<int>q;
        q.push(start);
        color[start]=0;
        
        while(!q.empty()){
            int node=q.front();
            q.pop();
            
            for(auto neighbour:adj[node]){
                if(color[neighbour]==-1){
                    color[neighbour]=!color[node];
                    q.push(neighbour);
                }
                else{
                    if(color[neighbour]==color[node]){
                        return false;
                    }
                }
            }
        }
        
        return true;
    }
public:
	bool isBipartite(int V, vector<int>adj[]){
	    vector<int> color(V,-1);
	    
	    for(int i=0;i<V;i++){
	        if(color[i]==-1){
	            if(check(i,V,color,adj)==false){
	                return false;
	            }
	        }
	    }
	    
	    return true;
	}

};
