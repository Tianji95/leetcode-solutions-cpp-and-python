class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
		if (root) {
			queue<TreeNode*> q;
			q.push(root);
			for (; !q.empty();) {
				auto t = &q.front();
				if (*t) {
					s += to_string((*t)->val);
					q.push((*t)->left);
					q.push((*t)->right);
				}
				s.push_back(',');
				q.pop();
			}
		}
		return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* root = nullptr;
		const char* p = data.c_str();
		int n;
		if (*p) {
			queue<TreeNode*> q;
			q.push(root = new TreeNode(strtol(p, const_cast<char**>(&p), 10)));
			for (; !q.empty();) {
				auto t = &q.front();
				if (*++p != ',') { q.push((*t)->left = new TreeNode(strtol(p, const_cast<char**>(&p), 10))); }
				if (*++p != ',') { q.push((*t)->right = new TreeNode(strtol(p, const_cast<char**>(&p), 10))); }
				q.pop();
			}
		}
		return root;
    }
};