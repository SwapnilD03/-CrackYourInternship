class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        auto it=find(wordList.begin(),wordList.end(),endWord);
        if(it==wordList.end()) return 0;

        unordered_map<string,list<string>> neighbour;
        wordList.push_back(beginWord);

        for(auto word:wordList){
            for(int j=0;j<word.length();j++){
                string pattern=word.substr(0,j)+"*"+word.substr(j+1);
                neighbour[pattern].push_back(word);
            }
        }

        unordered_map<string,bool> visited;
        visited[beginWord]=true;
        deque<string> q;
        q.push_back(beginWord);
        int res=1;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                string wd=q.front();
                q.pop_front();
                if(wd==endWord){
                    return res;
                }

                for(int j=0;j<wd.length();j++){
                    string pattern=wd.substr(0,j)+"*"+wd.substr(j+1);
                    for(auto nbr:neighbour[pattern]){
                        if(!visited[nbr]){
                            visited[nbr]=true;
                            q.push_back(nbr);
                        }
                    }
                }

            }
            res++;            
        }
        return 0;
    }
};
