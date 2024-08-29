class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        
        unordered_map<int,list<int>> adj;
        for(int i=0;i<n;i++){
            adj[manager[i]].push_back(i);
        }

        deque<pair<int,int>> q;
        q.push_back({headID,0});

        int time=0;
        while(!q.empty()){
            pair<int,int> p=q.front();
            int Id=p.first,currTime=p.second;
            q.pop_front();
            time=max(time,currTime);
            for(auto emp:adj[Id]){
                q.push_back({emp,currTime+informTime[Id]});
            }
        }
        return time;
    }
};
