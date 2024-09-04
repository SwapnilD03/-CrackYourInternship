class Solution {
public:
    bool solve(vector<vector<int>>&matrix,vector<vector<int>> &ans,int i,int j,int n ){
        if(i>=n || j>=n) return false;
        
        ans[i][j]=1;
        
        if(i==n-1 && j==n-1){
            return true;
        }
        
        int jumps=matrix[i][j];
        
        for(int k=1;k<=jumps;k++){
            if(solve(matrix,ans,i,j+k,n) ) return true;
            if(solve(matrix,ans,i+k,j,n)) return true;
        }
        
        ans[i][j]=0;
        return false;
        
    }
	vector<vector<int>> ShortestDistance(vector<vector<int>>&matrix){
	    int n=matrix.size();
	    vector<vector<int>> ans(n,vector<int>(n,0));
	    if(solve(matrix,ans,0,0,n))
	    return ans;
	    else
	    return {{-1}};
	}

};
