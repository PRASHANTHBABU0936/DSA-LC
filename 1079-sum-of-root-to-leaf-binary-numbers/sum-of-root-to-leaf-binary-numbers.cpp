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
void hell(vector <int>&h,string res,TreeNode* &root){
    if (root == NULL) return;
        res = res + to_string(root->val);

        if (root->left == NULL && root->right == NULL) {
            h.push_back(stoi(res, 0, 2));
            return;
        }

hell(h,res,root->left);
hell(h,res,root->right);

}
    int sumRootToLeaf(TreeNode* root) {
        if(root == NULL) return 0;
        string res="";
        vector<int> h;
        hell(h,res,root);
        int sum=0;
        for(int i = 0;i<h.size();i++){
            sum+=h[i];
        }
    return sum;}
};