class Solution {
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        vector<double> angles;
        int cnt=0;
        for(auto p:points){
            int dx=p[0]-location[0];
            int dy=p[1]-location[1];

            if(dx==0 && dy==0){
                cnt++;
                continue;
            }
            angles.push_back(atan2(dy,dx)*(180/M_PI));
        }

        sort(angles.begin(),angles.end());
        vector<double> tmp=angles;
        for(auto d:angles){
            tmp.push_back(d+360);
        }
        int res=cnt;
        for(int i=0,j=0;i<tmp.size();i++){
            while(tmp[i]-tmp[j]>angle){
                j++;
            }
            res=max(res,cnt+i-j+1);
        }
        return res;
    }
};
