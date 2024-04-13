    TreeNode* bstFromPreorder1(vector<int>& preorder) {
        int pos =0;
        return bst(preorder, pos, INT_MAX, INT_MIN); 
    }
    
    TreeNode*bst(vector<int>&preorder, int &pos, int max, int min){
        if (pos>=preorder.size()) return NULL;
        int val = preorder[pos];
        if (val > max || val <min) return NULL;
        ++pos;
        TreeNode* node = new TreeNode(val);
        node->left = bst(preorder, pos, val, min);
        node->right = bst(preorder, pos, max, val);
        return node;
    }
