class Solution {
public:
void dfs( unordered_map<int,vector<int>>&adj, vector<int>&vis,int s){{
vis[s]=1;
for(auto v:adj[s]){
    if(!vis[v]){
      
     dfs(adj,vis,v);}
}
}
}
    bool validPath(int n, vector<vector<int>>& edges, int s, int d) {
        //using dfs and using bfs
        //source se dfc call kare agar sb path pe chala gaya to done
       unordered_map<int,vector<int>>adj;
       for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
         int v=edges[i][1];
         adj[u].push_back(v);
          adj[v].push_back(u);
       }
       vector<int>vis(n+1,0);
       dfs(adj,vis,s);
       if(vis[d]==1)return 1;
        return 0;
    }
};
