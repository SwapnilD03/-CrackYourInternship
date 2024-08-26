class Solution {
public:
    int findParent(int n,vector<int>&parent){
        if(n==parent[n]){
            return n;
        }
        return parent[n]=findParent(parent[n],parent);
    }

    bool unionFind(int n1,int n2,vector<int> &parent, vector<int> &rank){
        int p1=findParent(n1,parent);
        int p2=findParent(n2,parent);

        if(p1==p2){
            return false;
        }

        if(rank[p1]>rank[p2]){
            parent[p2]=p1;
        }
        else if(rank[p2]>rank[p1]){
            parent[p1]=p2;
        }
        else{
            parent[p2]=p1;
            rank[p1]++;
        }

        return true;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int> parent(n+1);
        for(int i=1;i<=n;i++){
            parent[i]=i;
        }

        vector<int> rank(n+1,1);

        for(auto nodes:edges){
            if(!unionFind(nodes[0],nodes[1],parent,rank)){
                return {nodes[0],nodes[1]};
            }
        }

        return {};
    }
};
