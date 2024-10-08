class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    int m=edges.size();
	    vector<int> dist(n+1,1e9);
	    
	    dist[1]=0;
	    
	    for(int i=1;i<=n;i++){
	        for(int j=0;j<m;j++){
	            int u=edges[j][0];
	            int v=edges[j][1];
	            int wt=edges[j][2];
	            
	            if(dist[u]!=1e9 && ((dist[u]+wt)<dist[v])){
	                dist[v]=dist[u]+wt;
	            }
	        }
	    }
	    
	    int flag=0;
	    
	    for(int j=0;j<m;j++){
	            int u=edges[j][0];
	            int v=edges[j][1];
	            int wt=edges[j][2];
	            
	            if(dist[u]!=1e9 && ((dist[u]+wt)<dist[v])){
	                flag=1;
	            }
	    }
	    
	    return flag;
	    
	    
	}
};
