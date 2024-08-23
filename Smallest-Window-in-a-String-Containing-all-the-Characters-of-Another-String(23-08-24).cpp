class Solution
{
    public:
    
    string smallestWindow (string s, string p)
    {
        if(p.empty()) return "";

        vector<int> countT(26,0);
        vector<int> window(26,0);
        int count=0;
        for (char c : p) {
            if(countT[c-'a']==0){
                countT[c-'a']=1;count++;
            }
            else
            countT[c-'a']++;
        }

        int have = 0, need = count;
        int left = 0, right = 0;
        int minLen = INT_MAX;
        int startIdx = 0;

        while (right < s.size()) {
            char c = s[right];
            window[c-'a']++;

            if (countT[c-'a']!=0 && window[c-'a'] == countT[c-'a']) {
                have++;
            }

            while (have == need) {
                if ((right - left + 1) < minLen) {
                    minLen = right - left + 1;
                    startIdx = left;
                }

                window[s[left]-'a']--;

                if (countT[c-'a'] && window[s[left]-'a'] < countT[s[left]-'a']) {
                    have--;
                }

                left++;
            }

            right++;
        }

        return minLen == INT_MAX ? "-1" : s.substr(startIdx, minLen);
    }
};
