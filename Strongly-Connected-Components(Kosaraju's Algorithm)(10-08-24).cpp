class Solution
{
	public:

	void dfs(int i,unordered_map<int,bool> &visited,stack<int> &st,vector<vector<int>>& adj){
	    visited[i]=true;
	    
	    for(auto neighbour:adj[i]){
	        if(!visited[neighbour]){
	            dfs(neighbour,visited,st,adj);
	        }
	    }
	    st.push(i);
	}
	
	void revDFS(int i,unordered_map<int,bool> &visited,unordered_map<int,list<int>> &adj){
	    visited[i]=true;
	    
	    for(auto neighbour:adj[i]){
	        if(!visited[neighbour]){
	            revDFS(neighbour,visited,adj);
	        }
	    }
	    
	}
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        stack<int> st;
        
        unordered_map<int,bool> visited;
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(i,visited,st,adj);
            }
        }
        
    unordered_map<int,list<int>> transpose;
        
        for(int i=0;i<V;i++){
            visited[i]=false;
            for(auto neighbour:adj[i]){
                transpose[neighbour].push_back(i);
            }
        }
        int count=0;
        while(!st.empty()){
            int top=st.top();
            st.pop();
            if(!visited[top]){
                count++;
               revDFS(top,visited,transpose);
            }
        }
        
        return count;
    }
};
