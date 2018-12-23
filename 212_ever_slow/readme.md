class Solution {

    struct TrieNode {
            bool isWord = false;
            TrieNode* c[26] = {0};
        };
    class Trie {
        public:
        TrieNode* root;
        /** Initialize your data structure here. */
        Trie() {
            root = new TrieNode();
        }

        /** Inserts a word into the trie. */
        void insert(string word) {
            TrieNode* cr = root;
            for(char c : word) {
                if((cr->c)[c-'a'] != NULL) cr = (cr->c)[c-'a'];
                else {
                    (cr->c)[c-'a'] = new TrieNode();
                    cr = (cr->c)[c-'a'];
                }
            }
            cr->isWord = true;
        }
    };
public:
    void dfs(int i, int j, TrieNode* root, unordered_set<string>& res, vector<vector<char>>& board,
            string& s) {
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] == '*') return;
        char c = board[i][j];
        board[i][j] = '*';
        
        if(root->c[c-'a'] != NULL) {
            s+=c;
            if(root->c[c-'a']->isWord) res.insert(s);
            dfs(i+1, j, root->c[c-'a'], res, board, s);
            dfs(i-1, j, root->c[c-'a'], res, board, s);
            dfs(i, j+1, root->c[c-'a'], res, board, s);
            dfs(i, j-1, root->c[c-'a'], res, board, s);
            s.pop_back();
        }
        
        
        board[i][j] = c;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie trie = Trie();
        unordered_set<string> res;
        for(string& s : words) trie.insert(s); 
        string st = "";
        for(int i = 0; i < board.size(); ++i) {
            for(int j = 0; j < board[i].size(); ++j) {
                dfs(i, j, trie.root, res, board, st);
            }
        }
        
        vector<string> str;
        for(const string& s : res) {
            str.push_back(s);
        }
        return str;
    }
};