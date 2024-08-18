class Solution {
public:
    int n;
    vector<int> bit;

    void update(int val,int idx){
        while(idx<=n){
            bit[idx]+=val;
            idx+=(idx & -idx);
        }
    }

    int query(int idx){
        int ans=0;
        while(idx>0){
            ans+=bit[idx];
            idx-=(idx & -idx);
        }

        return ans;
    }
  
    vector<int> countSmaller(vector<int>& nums) {
        n=nums.size();
        bit.resize(n+1,0);
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            v.push_back({nums[i],i});
        }

        sort(v.begin(),v.end());

        vector<int> res(n,0);

        for(auto& [ele,idx]:v){
            update(1,idx+1); 
            res[idx]=query(n)-query(idx+1);
        }
        return res;
    }
};
