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
bool hell(TreeNode* &p,TreeNode* &q){
// if(!p || !q) return false;
if(!p && !q) return true;

        if(p && !q) return false;
        if(!p && q) return false;

if(p->val != q->val) return false;

return hell(p->right, q->left) &&
       hell(p->left, q->right);
}

    bool isSymmetric(TreeNode* root) {
        if(!root->left && !root->right) return true;
        if(root->left && !root->right) return false;
        if(root->right && !root->left) return false;
        return hell(root->left,root->right);  }};