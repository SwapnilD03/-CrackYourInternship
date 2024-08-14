class Solution {
public:

    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> ps(n);
        stack<int>st1;
       
        for(int i=0;i<n;i++){
            while(!st1.empty() && heights[st1.top()]>=heights[i]){
                st1.pop();
            }

            if(st1.empty()){
                ps[i]=-1;
            }
            else{
                ps[i]=st1.top();
            }
            st1.push(i);
        }

        vector<int> ns(n);
        stack<int>st2;
        for(int i=n-1;i>=0;i--){
            while(!st2.empty() && heights[st2.top()]>=heights[i]){
                st2.pop();
            }

            if(st2.empty()){
                ns[i]=n;
            }
            else{
                ns[i]=st2.top();
            }
            st2.push(i);
        }

        int maxi=0;
        for(int i=0;i<n;i++){
            int currArea=(ns[i]-ps[i]-1)*heights[i];

            maxi=max(maxi,currArea);
        }

        return maxi;
    }
};
