class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> colorCount={0,0,0};
        int n=nums.size();
        for(int i=0;i<n;i++){
            int val=nums[i];
            colorCount[val]++;
        }
        int ind=0;
        for(int i=0;i<3;i++){
            for(int j=0;j<colorCount[i];j++){
                nums[ind++]=i;
            }
        }

    }
};
