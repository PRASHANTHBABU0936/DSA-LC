/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
void hell( vector<int> &res,TreeNode* root){
    if(root == NULL) return;
    hell(res,root->left);
    res.push_back(root->val);
    hell(res,root->right);
    // hell(res,root);
}
    vector<int> inorderTraversal(TreeNode* root) {
     vector<int> res;
hell(res,root);
    return res;
       
    }
};