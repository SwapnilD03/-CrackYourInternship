class Solution {
public:
    void solve(int pos,int n,int &count,vector<bool>&visited){
        if(pos>n){
            count++;
        }

        for(int i=1;i<=n;i++){
            if(!visited[i]&& (pos%i==0 || i%pos==0)){
                visited[i]=true;
                solve(pos+1,n,count,visited);
                visited[i]=false;
            }
        }
    }
    int countArrangement(int n) {
        int count=0;
        vector<bool> visited(n+1,0);
        solve(1,n,count,visited);
        
        return count;
        
    }
};
