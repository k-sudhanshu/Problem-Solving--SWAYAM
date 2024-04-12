class Solution
{
  public:
    Node *prev = NULL, *head = NULL;
    void helper(Node* node){
        if(!node)   return;
        helper(node->left);
        if(!prev)
            head = node;
        else{
            node->left = prev;
            prev->right = node;
        }
        prev = node;
        helper(node->right);
        prev->right = head;
        head->left = prev;
    }
    
    Node *bTreeToCList(Node *root)
    {
        if(!root)   return NULL;
        helper(root);
        return head;
    }
};
