class Solution {
public:
void iot(TreeNode* root,int x,int y,int &s){
    if(root==NULL)return;
    iot(root->left,x,y,s);
    int t=root->val;
    if(t>=x && t<=y)s+=t;
    iot(root->right,x,y,s);
}
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum=0;
        iot(root,low,high,sum);
        return sum;
        
    }
};
