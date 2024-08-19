class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans=0;
        int left=0;

        for(int right=1;right<colors.length();right++){
            if(colors[left]==colors[right]){
               if(neededTime[left]<neededTime[right]){
                ans+=neededTime[left];left=right;
               }
               else{
                ans+=neededTime[right];
               }
            }

            else{
                left=right;
            }
        }

        return ans;
    }
};
