class Solution{
  public:
    vector<int> nextSmaller(vector<int> arr){
        stack<int> st;
        int n=arr.size();
        vector<int> ans(n);
        for(int i=n-1;i>=0;i--){
            int num=arr[i];
            
            while(!st.empty() && arr[st.top()]>=num){
                st.pop();
            }
            
            ans[i]=(st.empty())?n:st.top();
            
            st.push(i);
        }
        return ans;
    }
    vector<int> prevSmaller(vector<int> arr){
        stack<int> st;
        int n=arr.size();
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            int num=arr[i];
            
            while(!st.empty() && arr[st.top()]>=num){
                st.pop();
            }
            
            ans[i]=(st.empty())?-1:st.top() ;
            
            
            st.push(i);
        }
        return ans;
    }
    
    int largestArea(vector<int> arr){
        vector<int> prev=prevSmaller(arr);
        vector<int> next=nextSmaller(arr);
        int maxi=INT_MIN;
        for(int i=0;i<arr.size();i++){
            int l=arr[i];
            int b=next[i]-prev[i]-1;
            int newArea=l*b;
            maxi=max(maxi,newArea);
        }
        return maxi;
    }
    int maxArea(int M[MAX][MAX], int n, int m) {
        int ans=INT_MIN;
        vector<int> height(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(M[i][j]==1){
                    height[j]++;
                }
                else{
                    height[j]=0;
                }
            }
            ans=max(ans,largestArea(height));
            
        }
        return ans;
    }
};
