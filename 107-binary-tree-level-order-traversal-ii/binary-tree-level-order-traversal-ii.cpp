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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root == NULL) return {};
         vector<vector<int>> res;
queue<TreeNode*> q;
q.push(root);
while(!q.empty()){
    int n = q.size();
            vector<int> ans;

    for(int i=0;i<n;i++){
        TreeNode* hell=q.front();
        ans.push_back(hell->val);
if(hell->left) q.push(hell->left);
if(hell->right)q.push(hell->right);
q.pop();
    }
res.push_back(ans);
}
reverse(res.begin(),res.end());
 return res;   }
};