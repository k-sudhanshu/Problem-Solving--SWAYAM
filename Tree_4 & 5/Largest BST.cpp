class Solution{
    public:
    
    int maxval;
    int minval;
    bool isBST;
    int size;
    
    Solution solve(Node* root, int& maxans){

        if(root == NULL)
            return {INT_MIN, INT_MAX, true, 0};
        
        Solution left = solve(root->left, maxans);
        Solution right = solve(root->right, maxans);
    
        Solution curr;
        curr.maxval = max(root->data, right.maxval);
        curr.minval = min(root->data, left.minval);
        curr.size = left.size + right.size + 1;
    
        if(left.isBST && right.isBST && 
            (root->data < right.minval && root->data > left.maxval)) 
            curr.isBST = true;
        
        else 
            curr.isBST = false;
    
        if(curr.isBST)
            maxans = max(maxans, curr.size);
        
        return curr;
    
    }
    
    int largestBst(Node *root)
    {
        int maxans = 0;
        Solution ans = solve(root, maxans);
        return maxans;
    }
};
