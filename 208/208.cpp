class Tree{
public:
    Tree* nexts[26] = {nullptr};
    bool isEnd;
    Tree():isEnd(false){
    }
};
class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new Tree();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        int len = word.size();
        Tree* now = root;
        for(int i = 0; i < len; i++){
            int idx = word[i]-'a';
            if(now->nexts[idx] == nullptr){
                now->nexts[idx] = new Tree();
            }
            now = now->nexts[idx];
        }
        now->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        int len = word.size();
        Tree* now = root;
        for(int i = 0; i < len; i++){
            int idx = word[i]-'a';
            if(now->nexts[idx] == nullptr){
                return false;
            }
            now = now->nexts[idx];
        }
        if(!now->isEnd)
            return false;
        return true;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        int len = prefix.size();
        Tree* now = root;
        for(int i = 0; i < len; i++){
            int idx = prefix[i]-'a';
            if(now->nexts[idx] == nullptr){
                return false;
            }
            now = now->nexts[idx];
        }
        return true;
    }
    Tree* root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */