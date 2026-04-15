class TrieNode{
    public:
        vector<TrieNode*> children;
        bool end;

        TrieNode(){
            children = vector<TrieNode*>(26, nullptr);
            end = false;
        }
};

class WordDictionary {
public:
    TrieNode* root;

    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* cur = root;
        for (char c : word){
            if (cur->children[c-'a'] == nullptr){
                cur->children[c-'a'] = new TrieNode();
            }
            cur = cur->children[c-'a'];
        }
        cur->end = true;
    }
    
    bool search(string word) {
        return dfs(word, 0, root);
    }

    bool dfs(string word, int j, TrieNode* root){
        TrieNode* cur = root;
        for(int i = j; i < word.length(); i++){
            char c = word[i];
            if (c == '.'){
                for (auto child : cur->children){
                    if (child != nullptr && dfs(word,i+1,child)){
                        return true;
                    }
                }
                return false;
            }
            else{
                if (cur->children[c-'a'] == nullptr){
                    return false;
                }
                cur = cur->children[c-'a'];
            }
        }
        return cur->end;
    }
};
