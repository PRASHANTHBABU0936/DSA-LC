class Solution {
public:
    void hell(TreeNode* root, string path, vector<string>& res) {
        // if (root == NULL) return;

        path += to_string(root->val);

        if (root->left == NULL && root->right == NULL) {
            res.push_back(path);
            return;
        }

        path += "->";

        if (root->left)  hell(root->left, path, res);
        if (root->right) hell(root->right, path, res);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (root == NULL) return res;

        hell(root, "", res);
        return res;
    }
};
