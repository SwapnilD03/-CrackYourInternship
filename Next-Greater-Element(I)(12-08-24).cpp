class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> mp;
        stack<int> st;
        for(auto num : nums2){
            while (!st.empty() && st.top() < num){
                mp[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }
        vector<int> ans;
        for(auto num : nums1){
            if(mp.find(num) != mp.end()){
                ans.push_back(mp[num]);
            }else{
                ans.push_back(-1);
            }
        }

        return ans;
    }
};
