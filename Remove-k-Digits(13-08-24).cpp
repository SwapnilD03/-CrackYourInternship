class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> stack;
        
        for (char digit : num) {
            while (!stack.empty() && k > 0 && stack.top() > digit) {
                stack.pop();
                k--;
            }
            stack.push(digit);
        }
        
        
        while (k > 0 && !stack.empty()) {
            stack.pop();
            k--;
        }
        
        
        string ans;
        while (!stack.empty()) {
            ans+= stack.top();
            stack.pop();
        }
        
        reverse(ans.begin(),ans.end());
        
        size_t pos = ans.find_first_not_of('0');
        ans = (pos == std::string::npos) ? "0" : ans.substr(pos);
        
        return ans;
    }
