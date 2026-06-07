class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        
        unordered_map<int, TreeNode*> mp;
        unordered_set<int> child;
        
        for (auto &d : descriptions) {
            int parent = d[0];
            int ch = d[1];
            int isLeft = d[2];
            
            // create parent if not exists
            if (mp.find(parent) == mp.end())
                mp[parent] = new TreeNode(parent);
            
            // create child if not exists
            if (mp.find(ch) == mp.end())
                mp[ch] = new TreeNode(ch);
            
            // connect
            if (isLeft == 1)
                mp[parent]->left = mp[ch];
            else
                mp[parent]->right = mp[ch];
            
            // mark child
            child.insert(ch);
        }
        
        // find root (not a child)
        for (auto &it : mp) {
            if (child.find(it.first) == child.end())
                return it.second;
        }
        
        return NULL;
    }
};