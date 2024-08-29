class Solution 
{
    public:
    
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    int i=KnightPos[0]-1,j=KnightPos[1]-1;
	    int x=TargetPos[0]-1,y=TargetPos[1]-1;
	    vector<vector<int>> dp(N,vector<int>(N,-1));
	    
	    if(i==x && j==y) return 0;
	    
	    vector<vector<int>> directions={{1,2},{-1,2},{2,1},{-2,1},{2,-1},{-2,-1},{-1,-2},{1,-2}};
	    queue<pair<int,int>> q;
	    q.push({i,j});
	    
	    vector<vector<bool>> visited(N,vector<bool>(N,false));
	    visited[i][j]=true;
	    int steps=0;
	    
	    while(!q.empty()){
	        steps++;
	        int size=q.size();
	        for(int i=0;i<size;i++){
	            
	            pair<int,int> p=q.front();
	            q.pop();
	            int r=p.first,c=p.second;
	            for(auto d:directions){
	                int row=r+d[0],col=c+d[1];
	                if(row==x && col==y){
	                    return steps;
	                }
	                if(row<0 || row>=N || col<0 || col>=N || visited[row][col]){
	                    continue;
	                }
	                
	                visited[row][col]=true;
	                q.push({row,col});
	                
	                }
	            }
	            
	            
	            
	        }
	    
	    return steps;
	}
};
