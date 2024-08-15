class RandomizedCollection {
public:
    vector<int> numList;
    unordered_map<int,set<int>> mp;
    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        numList.push_back(val);
        mp[val].insert(numList.size()-1);
        if(mp[val].size()==1){
            return true;
        }
        else{
            return false;
        }
    }
    
    bool remove(int val) {
        auto it=mp.find(val);
        if(it!=mp.end()){
            auto pos=*it->second.begin();
            it->second.erase(it->second.begin());
            numList[pos]=numList.back();
            mp[numList.back()].insert(pos);
            mp[numList.back()].erase(numList.size()-1);
            numList.pop_back();
            if(it->second.size()==0){
                mp.erase(it);
            }
            return true;
        }
        return false;
        
    }
    
    int getRandom() {
        return numList[rand()%numList.size()];
    }
};
