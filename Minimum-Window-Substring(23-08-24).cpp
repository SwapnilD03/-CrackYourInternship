class Solution {
public:
    string minWindow(string s, string t) {
        if(t.empty()) return "";

        unordered_map<char, int> countT;
        unordered_map<char, int> window;

        for (char c : t) {
            countT[c]++;
        }

        int have = 0, need = countT.size();
        int left = 0, right = 0;
        int minLen = INT_MAX;
        int startIdx = 0;

        while (right < s.size()) {
            char c = s[right];
            window[c]++;

            if (countT.find(c) != countT.end() && window[c] == countT[c]) {
                have++;
            }

            while (have == need) {
                if ((right - left + 1) < minLen) {
                    minLen = right - left + 1;
                    startIdx = left;
                }

                window[s[left]]--;

                if (countT.find(s[left]) != countT.end() && window[s[left]] < countT[s[left]]) {
                    have--;
                }

                left++;
            }

            right++;
        }

        return minLen == INT_MAX ? "" : s.substr(startIdx, minLen);
    }
};
