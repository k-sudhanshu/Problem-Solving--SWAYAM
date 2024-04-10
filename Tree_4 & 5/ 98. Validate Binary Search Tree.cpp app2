class Solution {
public:
    bool isValidBST(TreeNode* root) {
        long pre = LONG_MIN;
        stack<TreeNode*> todo;
        while (root || !todo.empty()) {
            while (root) {
                todo.push(root);
                root = root -> left;
            }
            root = todo.top();
            todo.pop();
            if (root -> val <= pre) {
                return false;
            }
            pre = root -> val;
            root = root -> right;
        }
        return true;
    }
};
