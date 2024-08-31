class Solution
{
    public:
    
    vector <int> maxOfMin(int arr[], int n)
    {
       int nsl[n];
       int nsr[n];
       
       stack<int> st;
       for(int i=0;i<n;i++){
           while(!st.empty() && arr[i]<arr[st.top()]){
               nsr[st.top()]=i;
               st.pop();
           }
           st.push(i);
       }
       
       while(!st.empty()){
           nsr[st.top()]=n;
           st.pop();
       }
       
       for(int i=n-1;i>=0;i--){
           while(!st.empty() && arr[i]<arr[st.top()]){
               nsl[st.top()]=i;
               st.pop();
           }
           st.push(i);
       }
       while(!st.empty()){
           nsl[st.top()]=-1;
           st.pop();
       }
       
       int min_Len[n];
       for(int i=0;i<n;i++){
           min_Len[i]=(nsr[i]-nsl[i]-1);
       }
       
       vector<int> vec(n+1,0);
       for(int i=0;i<n;i++){
           vec[min_Len[i]]=max(vec[min_Len[i]],arr[i]);
       }
       
       for(int i=n-1;i>=1;i--){
           vec[i]=max(vec[i],vec[i+1]);
       }
       
       vector<int> ans;
       for(int i=1;i<=n;i++){
           ans.push_back(vec[i]);
       }
       return ans;
    }
};
