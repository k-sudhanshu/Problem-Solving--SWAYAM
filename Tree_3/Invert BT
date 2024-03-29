class Solution {
public:
    void invert(TreeNode* root){
        if(root == NULL)
            return;
        
        TreeNode* temp = NULL;
        temp = root->left;
        root->left = root->right;
        root->right = temp;
        
        invert(root->left);
        invert(root->right);
        
        return;
    }
    TreeNode* invertTree(TreeNode* root) {
        invert(root);
        return root;
    }
};
