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
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        queue <TreeNode*> q;
        q.push(root);
        int idx=0;
        
        while(!q.empty()){
            
int n = q.size();
idx++;
for(int i=1;i<=n;i++){
    TreeNode* hell=q.front();
            q.pop();
if(hell->left) q.push(hell->left);
if(hell->right)q.push(hell->right);
}
        }
    return idx;}
};