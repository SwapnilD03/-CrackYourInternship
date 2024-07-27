class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int ans = 0;
		    int n=cardPoints.size();
        for(int i=0;i<k;i++){
            ans+=cardPoints[i];
        }
        int currSum=ans;
        for(int i=k-1;i>=0;i--) {
			
            currSum-=cardPoints[i];
            currSum+=cardPoints[n-k+i];
			
			      ans = max(ans, currSum);
         }
        
        return ans;
    }
};
