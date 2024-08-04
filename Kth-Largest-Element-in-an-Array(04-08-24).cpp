class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;

        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        int i=1;
        int ans=0;
        while(!pq.empty() && i<=k){
            ans=pq.top();
            i++;
            pq.pop();
        }
        return ans;
    }
};
