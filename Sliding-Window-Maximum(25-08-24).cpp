class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int>dq;
        for(int i=0;i<k;i++){
            int ele=nums[i];
            while(!dq.empty() && ele>nums[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);

        }

        for(int i=k;i<nums.size();i++){
            ans.push_back(nums[dq.front()]);

            while(!dq.empty() && i-dq.front()>=k){
                dq.pop_front();
            }

            int ele=nums[i];

            while(!dq.empty() && ele>nums[dq.back()]){
                dq.pop_back();
            }

            dq.push_back(i);
       }

       ans.push_back(nums[dq.back()]);

       return ans;
    }
};
