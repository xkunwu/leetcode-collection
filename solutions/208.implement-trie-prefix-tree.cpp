class Trie {
	/** 208. Implement Trie (Prefix Tree)
	 * https://leetcode.com/problems/implement-trie-prefix-tree/
	 */
    struct TrieNode {
        TrieNode* children[26];
        bool isLeaf;

        TrieNode() {
            for (int i = 0; i < 26; ++i) {
                children[i] = nullptr;
            }
            isLeaf = false;
        }
    };

    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* pnode = root;
        for (const auto& c: word) {
            if (nullptr == pnode->children[c - 'a']) {
                pnode->children[c - 'a'] = new TrieNode();
            }
            pnode = pnode->children[c - 'a'];
        }
        pnode->isLeaf = true;
    }
    
    bool search(string word) {
        TrieNode* pnode = root;
        for (const auto& c: word) {
            if (nullptr == pnode->children[c - 'a']) {
                return false;
            }
            pnode = pnode->children[c - 'a'];
        }
        return pnode->isLeaf;
    }
    
    bool startsWith(string prefix) {
        TrieNode* pnode = root;
        for (const auto& c: prefix) {
            if (nullptr == pnode->children[c - 'a']) {
                return false;
            }
            pnode = pnode->children[c - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */