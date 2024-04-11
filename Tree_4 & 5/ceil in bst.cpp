void solve(Node* root,int i,int &ceil)
{
    if(root==NULL)
    return;
    if(root->data>i)
    ceil=root->data;
    if(root->data==i)
    {
        ceil=root->data;
        return;
    }
    if(root->data<i)
    solve(root->right,i,ceil);
    else
    solve(root->left,i,ceil);
}
int findCeil(Node* root, int input) {
    if (root == NULL) return -1;
    int ceil=-1;
    solve(root,input,ceil);
    return ceil;
}
