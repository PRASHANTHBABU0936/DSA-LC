class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;

        TreeNode* hell = root;

        while (hell != nullptr || !st.empty()) {

            while (hell != nullptr) {
                st.push(hell);
                hell = hell->left;
            }

            hell = st.top();
            st.pop();
            res.push_back(hell->val);

            hell = hell->right;
        }

        return res;
    }
};
