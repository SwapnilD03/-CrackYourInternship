class Solution {
public:
    int characterReplacement(string s, int k) {
        map<int,int> count;
        int res=0;

        int left=0;

        for(int right=0;right<s.length();right++){
            if(count.find(s[right])!=count.end()){
                count[s[right]]++;
            }
            else{
                count[s[right]]=1;
            }
            int maxi=0;
            for(auto i:count){
                maxi=max(maxi,i.second);
            }
            
            if((right-left+1)-maxi>k){
                count[s[left]]--;
                left++;
            }

            res=max(res,right-left+1);
        }

        return res;

    }
};
