class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> pq;
        unordered_map<char,int> count;
        for(auto t:tasks){
            if(count.find(t)!=count.end()){
                count[t]++;
            }
            else{
                count[t]=1;
            }
        }

        for(auto i:count){
            pq.push(i.second);
        }

        int time=0;
        deque<pair<int,int>> dq;

        while(!pq.empty() || !dq.empty() ){
            time++;
            if(!pq.empty()){
                int count=pq.top()-1;
                pq.pop();
                if(count!=0){
                    dq.push_back({count,time+n});
                }
            }
            if(!dq.empty() && dq.front().second==time){
                int ele=dq.front().first;
                dq.pop_front();
                pq.push(ele);
            }
        }

        return time;

    }
};
