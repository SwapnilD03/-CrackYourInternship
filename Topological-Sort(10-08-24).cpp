class Solution
{
	public:

	void dfs(int node,unordered_map<int,bool> &visited,stack<int> &st,vector<int> adj[]){
	    visited[node]=true;
	    
	    for(auto neighbour:adj[node]){
	        if(!visited[neighbour]){
	            dfs(neighbour,visited,st,adj);
	        }
	    }
	    
	    st.push(node);
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> ans;
	    stack<int> st;
	    
	    unordered_map<int,bool> visited;
	    for(int i=0;i<V;i++){
	        if(!visited[i]){
	            dfs(i,visited,st,adj);
	        }
	    }
	    
	    while(!st.empty()){
	        ans.push_back(st.top());
	        st.pop();
	    }
	    
	    return ans;
	}
};
