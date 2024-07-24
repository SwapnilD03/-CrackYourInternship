class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int ans;
        unordered_map<int,int> freq;

        for(int i=0;i<n;i++){
            if(freq.find(nums[i])!=freq.end()){
                freq[nums[i]]++;
            }
            else{
                freq[nums[i]]=1;
            }
        }

        for(auto it:freq){
            if(it.second>n/2){
                ans= it.first;break;
            }
        }

        return ans;
    }
};
