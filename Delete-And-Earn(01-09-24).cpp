class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int,int> count;
        for(auto i:nums){
            if(count.find(i)!=count.end()){
                count[i]++;
            }
            else{
                count[i]=1;
            }
        }
        vector<int> num;
        for(auto it:count){
            num.push_back(it.first);
        }

        sort(num.begin(),num.end());

        int e1=0,e2=0;

        for(int i=0;i<num.size();i++){
            int currEarn=num[i]*count[num[i]];
            if(i>0 && num[i]==num[i-1]+1){
                int tmp=e2;
                e2=max(e2,currEarn+e1);
                e1=tmp;
            }
            else{
                int tmp=e2;
                e2=e2+currEarn;
                e1=tmp;
            }
        }
        return e2;
    }
};
