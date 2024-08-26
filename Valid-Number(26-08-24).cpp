class Solution {
public:
    bool isNumber(string s) {
        int n = s.length();
        if (n == 0) return false;

        
        int start = 0, end = n - 1;
        while (start <= end && s[start] == ' ') start++;
        while (end >= start && s[end] == ' ') end--;

        
        if (start > end) return false;

        
        if (s[start] == '+' || s[start] == '-') start++;

        bool hasDigits = false;
        bool hasDot = false;
        bool hasExp = false;

        for (int i = start; i <= end; i++) {
            char ch = s[i];
            if (isdigit(ch)) {
                hasDigits = true;
            } else if (ch == '.') {
                
                if (hasDot || hasExp) return false;
                hasDot = true;
            } else if (ch == 'e' || ch == 'E') {
                
                if (hasExp || !hasDigits) return false;
                hasExp = true;
                hasDigits = false; 
                if (i < end && (s[i + 1] == '+' || s[i + 1] == '-')) i++; 
            } else {
                return false;  
            }
        }

        return hasDigits;  
    }
};
