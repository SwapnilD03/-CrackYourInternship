class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxi=0;
        int l=0,r=height.size()-1;
        while(l<r){
            int currArea=(r-l)*min(height[l],height[r]);
            maxi=max(maxi,currArea);
            if(height[l]<height[r]){
                l++;
            }
            else{
                r--;
            }
        }
        return maxi;
    }
};
