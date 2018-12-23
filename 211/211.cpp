class WordTree{
public:
	bool isWord;
	std::vector<WordTree*> children;
	WordTree() { 
        isWord = false; 
	    children = std::vector<WordTree*>(26, nullptr);
	}
    
};

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new WordTree();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        int len = word.size();
        WordTree* node = root;
        int idx = 0;
        for(int i = 0; i < len; i++){
            idx = word[i]-'a';
            if(node->children[idx]==nullptr){
                node->children[idx] = new WordTree();
            }
            node = node->children[idx];
        }
        node->isWord = true;
    }
    
    bool searchTree(WordTree* node, string& word, int idx, int len){
        if(idx == len)
            return node->isWord;
        if(word[idx] == '.'){
            for(int i = 0; i < 26; i++){
                if(node->children[i]!=nullptr && searchTree(node->children[i], word, idx+1, len)){
                    return true;
                }
            }
            return false;
        }
        else{
            int tmp = word[idx]-'a';
            if(node->children[tmp] == nullptr)
                return false;
            else
                return searchTree(node->children[tmp], word, idx+1, len);
        }
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return searchTree(root, word, 0, word.size());
    }
    WordTree* root;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */