class DisjointSet{
public:
    vector<int> rank,parent,size;
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<n;i++){
            parent[i]=i;
            size[i]=1;
        }
    }

    int findUPar(int node){
        if(node==parent[node]) return node;
        return parent[node]=findUPar(parent[node]);
    }

    void unionBySize(int u,int v){
        int uPar=findUPar(u);
        int vPar=findUPar(v);
        if(uPar==vPar) return;
        if(size[uPar]<size[vPar]){
            parent[uPar]=vPar;
            size[vPar]+=size[uPar];
        }
        else{
           parent[vPar]=uPar;
           size[uPar]+=size[vPar];
        }
    }

};

class Solution {
private:
    bool isValid(int r,int c,int n){
        if(r<0 || r>=n || c<0 || c>=n) return false;
        return true;
    }

public:
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        DisjointSet ds(n*n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    continue;
                }
                int dr[]={-1,0,1,0};
                int dc[]={0,-1,0,1};

                for(int ind=0;ind<4;ind++){
                    int newRow=i+dr[ind],newCol=j+dc[ind];
                    if(isValid(newRow,newCol,n) && grid[newRow][newCol]==1){
                        int nodeNo=i*n+j;
                        int adjNodeNo=newRow*n+newCol;
                        ds.unionBySize(nodeNo,adjNodeNo);
                    }
                }
            }
        }

        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    continue;
                }
                int dr[]={-1,0,1,0};
                int dc[]={0,-1,0,1};
                set<int> components;
                for(int ind=0;ind<4;ind++){
                    int newRow=i+dr[ind],newCol=j+dc[ind];
                    
                    if(isValid(newRow,newCol,n)){
                        if(grid[newRow][newCol]==1){
                            components.insert(ds.findUPar(newRow*n+newCol));
                        }
                    }
                }

                int sizeTotal=0;
                for(auto it:components){
                    sizeTotal+=ds.size[it];
                }

                maxi=max(maxi,sizeTotal+1);
            }
        }
        for(int cell=0;cell<n*n;cell++){
            maxi=max(maxi,ds.size[ds.findUPar(cell)]);
        }
        return maxi;
    }
};
