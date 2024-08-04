class Solution {
public:

    static bool cmp(pair<int,int> p1,pair<int,int> p2){
        return p1.second>p2.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;

        unordered_map<int,int> mp;

        for(int i=0;i<nums.size();i++){
            if(mp.find(nums[i])!=mp.end()){
                mp[nums[i]]++;
            }
            else{
                mp[nums[i]]=1;
            }
        }
        vector<pair<int,int>> v;
        for(auto it:mp){
            v.push_back(make_pair(it.first,it.second));
        }

        sort(v.begin(),v.end(),cmp);
        for(int i=0;i<k;i++){
            ans.push_back(v[i].first);
        }

        return ans;

    }
};
