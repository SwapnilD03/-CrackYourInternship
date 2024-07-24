class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int,int> freq;
        for(int i=0;i<nums.size();i++){
            if(freq.find(nums[i])!=freq.end()){
                ans.push_back(nums[i]);
            }
            else{
                freq[nums[i]]=1;
            }
        }
        return ans;
    }
};
