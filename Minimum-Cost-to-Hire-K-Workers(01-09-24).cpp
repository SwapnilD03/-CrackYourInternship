class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        double res=DBL_MAX;
        int n=quality.size();

        vector<pair<double,int>> worker_ratio(n);
        for(int worker=0;worker<n;worker++){
            worker_ratio[worker]=make_pair((double)wage[worker]/quality[worker],quality[worker]);
        }

        sort(worker_ratio.begin(),worker_ratio.end());

        priority_queue<int,vector<int>> pq;

        int sum_quality=0;
        for(int i=0;i<k;i++){
            pq.push(worker_ratio[i].second);
            sum_quality+=worker_ratio[i].second;
        }

        double managerRatio=worker_ratio[k-1].first;
        res=managerRatio*sum_quality;

        for(int manager=k;manager<n;manager++){
             managerRatio=worker_ratio[manager].first;
             vector<double> grp;
             
             pq.push(worker_ratio[manager].second);
             sum_quality+=worker_ratio[manager].second;

             if(pq.size()>k){
                sum_quality-=pq.top();
                pq.pop();
             }

             res=min(res,sum_quality*managerRatio);
        }
        return res;
    }
};
