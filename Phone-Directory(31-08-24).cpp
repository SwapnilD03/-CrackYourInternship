class TrieNode {
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch) {
        data = ch;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode* root, const string& word) {
        if (word.empty()) {
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        TrieNode* child;

        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        insertUtil(child, word.substr(1));
    }

    void insert(const string& word) {
        insertUtil(root, word);
    }

    void helper(TrieNode* curr, vector<string>& tmp, string pref) {
        if (curr->isTerminal) {
            tmp.push_back(pref);
        }

        for (char ch = 'a'; ch <= 'z'; ch++) {
            TrieNode* next = curr->children[ch - 'a'];
            if (next != NULL) {
                helper(next, tmp, pref + ch);
            }
        }
    }

    vector<vector<string>> getSuggestions(const string& str) {
        TrieNode* prev = root;
        vector<vector<string>> ans;
        string pref = "";
        int i;

        for (i = 0; i < str.length(); i++) {
            char lastChar = str[i];
            pref.push_back(lastChar);

            TrieNode* curr = prev->children[lastChar - 'a'];
            if (curr == NULL) {
                break;
            }

            vector<string> tmp;
            helper(curr, tmp, pref);

            if (tmp.empty()) {
                ans.push_back({ "0" });
            } else {
                ans.push_back(tmp);
            }

            prev = curr;
        }

        while (i < str.length()) {
            ans.push_back({ "0" });
            i++;
        }

        return ans;
    }
};

class Solution {
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s) {
        Trie t;

        for (int i = 0; i < n; i++) {
            t.insert(contact[i]);
        }

        return t.getSuggestions(s);
    }
};
