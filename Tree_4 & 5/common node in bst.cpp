class Solution
{
    public:
    //Function to find the nodes that are common in both BST. 
     void io(Node* root,map<int,int> &m)
    {
        if(!root) return;
        io(root->left,m);
        m[root->data]++;
        io(root->right,m);
    }
    vector <int> findCommon(Node *root1, Node *root2)
    {
       map<int,int> m;
       vector<int> v;
       io(root1,m);
       io(root2,m);
       for(auto it:m){
         if(it.second>1) v.push_back(it.first);}
       return v;
    }
};
