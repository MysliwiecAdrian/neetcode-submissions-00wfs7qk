class TrieNode{
    public:
        unordered_map<char, TrieNode*> children;
        bool end = false;
};


class PrefixTree {
    TrieNode* root;
public:
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* cur = root;
        for (char c : word){
            if (cur->children.find(c) == cur->children.end()){
                cur->children[c] = new TrieNode();
            }
            cur = cur->children[c];
        }
        cur->end = true;
    }
    
    bool search(string word) {
        TrieNode* cur = root;
        for (char c : word){
            if (cur->children.find(c) == cur->children.end()){
                return false;
            }
            cur = cur->children[c];
        }
        return cur->end;
    }
    
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for (char c : prefix){
            if (cur->children.find(c) == cur->children.end()){
                return false;
            }
            cur = cur->children[c];
        }
        return true;
    }
};
