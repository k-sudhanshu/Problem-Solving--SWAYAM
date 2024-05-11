class Solution {
public:
    int find(int x,vector<int>& parent){
        if(parent[x]==x)return x;
        else
        return find(parent[x],parent);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        //basicaly here the idea is every connection between node should be unique, if any node is making cycle this should be removed, 
        //so in disjoint set we say when parent of 2 nodes is same means it should be removed
        int n=edges.size();//no.of nodes
        if(n==0)return {};
        vector<int>parent(n+1);
        for(int i=1;i<=n;i++){
            parent[i]=i;
        }
        for(int i=0;i<edges.size();i++){
            int par1=find(edges[i][0],parent);
            int par2=find(edges[i][1],parent);
            if(par1==par2){
                return edges[i];
            }else{
                parent[par1]=par2;
            }
        }
        return {};
 
        
    }
};
