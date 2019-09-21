/** 677. Map Sum Pairs
	https://leetcode.com/problems/map-sum-pairs/
	Implement a MapSum class with insert, and sum methods.

	For the method insert, you'll be given a pair of (string, integer). The string represents the key and the integer represents the value. If the key already existed, then the original key-value pair will be overridden to the new one.

	For the method sum, you'll be given a string representing the prefix, and you need to return the sum of all the pairs' value whose key starts with the prefix.
*/

class MapSum {
    typedef unordered_map<string, int> vmap_type;
    vmap_type vmap;
public:
    /** Initialize your data structure here. */
    MapSum() {

    }

    void insert(string key, int val) {
        vmap[key] = val;
    }

    int sum(string prefix) {
        int res = 0;
        for (vmap_type::iterator it = vmap.begin(); it != vmap.end(); ++it) {
            if (0 == it->first.compare(0, prefix.size(), prefix))
                res += it->second;
        }
        return res;
    }
};

class MapSum {
    /** Using Prefix Tree, aka Trie
    **/
    struct PrefixNode {
        int val;
        unordered_map<int, PrefixNode*> children;
        PrefixNode* parent;
        PrefixNode(int val, PrefixNode* parent = NULL) : val(val), parent(parent) {}
    };
    typedef unordered_map<int, PrefixNode*> children_type;
    PrefixNode* root = NULL;
public:
    /** Initialize your data structure here. */
    MapSum() {
        root = new PrefixNode(0, NULL);
    }

    void insert(string key, int val) {
        PrefixNode* curr = root;
        string::iterator it;
        // cout << "=== insert: " << key << ", " << val << endl;
        for (it = key.begin(); it != key.end(); ++it) {
            // cout << *it << ", " << curr->val << " - > ";
            if (0 == curr->children.count(*it)) {
                curr->children[*it] = new PrefixNode(val, curr);
                curr = curr->children[*it];
            } else {
                curr->children[*it]->val += val;
                curr = curr->children[*it];
            }
            // cout << curr->val << endl;
        }
        // update if the key is identical: traverse upwards
        if (curr->children.empty()) {
            int delta = val - curr->val;
            if (0 == delta) return;
            while (NULL != curr->parent) {
                curr->val += delta;
                curr = curr->parent;
            }
        }
    }

    int sum(string prefix) {
        PrefixNode* curr = root;
        string::iterator it;
        // cout << "=== sum: " << prefix << endl;
        for (it = prefix.begin(); it != prefix.end(); ++it) {
            // cout << *it << ", " << curr->val << endl;
            if (0 == curr->children.count(*it)) break;
            curr = curr->children[*it];
        }
        if (it == prefix.end()) return curr->val;
        else return 0;
    }
};
