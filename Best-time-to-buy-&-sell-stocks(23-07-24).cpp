class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l=0,r=l+1;
        int maxi=0;
        while(r<prices.size()){
            if(prices[r]-prices[l]<0){
                l++;
            }
            else{
                maxi=max(maxi,prices[r]-prices[l]);
                r++;
            }
        }
        return maxi;
    }
};
