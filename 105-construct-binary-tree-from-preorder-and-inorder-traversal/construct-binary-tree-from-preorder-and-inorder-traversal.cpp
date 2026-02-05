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
  int idx = 0; 
 TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int start, int end) {
              if (start > end) return NULL;

 TreeNode* root = new TreeNode(preorder[idx]);
        idx++;

         int pos = start;
        while (inorder[pos] != root->val) pos++;
        root->left = solve(preorder, inorder, start, pos - 1);
root->right = solve(preorder, inorder, pos + 1, end);

        return root;}




    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return solve(preorder,inorder,0,inorder.size()-1);
    }
};