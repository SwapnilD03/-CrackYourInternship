class Solution{
    private:
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
    public:
    string findOrder(string dict[], int N, int K) {
        vector<int> adj[K];
        
        for(int i=0;i<N-1;i++){
            string s1=dict[i],s2=dict[i+1];
            int ind=0;
            while(ind<min(s1.length(),s2.length())){
                if(s1[ind]!=s2[ind]){
                    adj[s1[ind]-'a'].push_back(s2[ind]-'a');break;
                }
                ind++;
            }
        }
        
        vector<int> Sort=topoSort(K,adj);
        
        string ans="";
        for(auto it:Sort){
            ans=ans+char(it+'a');
        }
        
        return ans;
        
    }
};
