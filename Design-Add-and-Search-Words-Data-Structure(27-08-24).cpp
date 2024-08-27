class TrieNode{
    public: 
    char data;
    TrieNode* children[26];
    bool isTerminal;
    TrieNode(char ch){
        data=ch;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        isTerminal=false;
    }
};

class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() {
        root=new TrieNode('\0');
    }
    
    void insertUtil(TrieNode* root,string word){
        //base case
        if(word.length()==0){
            root->isTerminal=true;
            return;
        }
        
        int index=word[0]-'a';
        TrieNode* child;
        
        //present
        if(root->children[index]!=NULL){
            child=root->children[index];
        }

        else{
            //absent
            child=new TrieNode(word[0]);
            root->children[index]=child;
        }

        insertUtil(child,word.substr(1));

    }

    void addWord(string word) {
        insertUtil(root,word);
    }
    
    bool searchUtil(TrieNode* root,string word){
        if(word.length()==0){
            return root->isTerminal;
        }
        char curr=word[0];
        if(curr!='.'){
        int index=word[0]-'a';
        TrieNode* child;

        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        else{
            return false;
        }
        return searchUtil(child,word.substr(1));
        }
        else{
            for(int i=0;i<26;i++){
                TrieNode* child=root->children[i];
                if(child!=NULL){
                    if(searchUtil(child,word.substr(1))){
                        return true;
                    }
                }
            }
            return false;
        }
    }


    bool search(string word) {
        return searchUtil(root,word);
    }
};
