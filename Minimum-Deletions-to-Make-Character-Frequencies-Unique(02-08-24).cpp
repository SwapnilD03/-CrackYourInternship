class Solution {
public:
    int minDeletions(string s) {
        int res=0;
        unordered_map<char,int> count;
        set<int> freq;
        for(int i=0;i<s.length();i++){
            char ch=s[i];
            if(count.find(ch)!=count.end()){
                count[ch]++;
            }
            else{
                count[ch]=1;
            }
        }

        for(auto it:count){
            while(it.second>0 && freq.contains(it.second) ){
                it.second--;
                res++;
            }
            freq.insert(it.second);
        }
        return res;
    }
};
