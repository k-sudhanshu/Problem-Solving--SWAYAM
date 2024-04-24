class Solution {
public:
bool dfs(vector<vector<int>>& graph,int u,vector<int>color,int c){
    if(color[u]!=-1){
     if(color[u]==c)return false;
     return true;
    }
    color[u]=c;
    for(auto v:graph[u]){
        if(color[v]==-1){
            if(!dfs(graph,v,color,1-c))return false;
        }
        else{
            if(color[u]==color[v])return false;
        }
    }
    return true;
}
    bool isBipartite(vector<vector<int>>& graph) {
   
        unordered_map<int,vector<int>>adj;
        int n=graph.size();
        vector<int>color(n,-1);
        for(int i=0;i<n;i++){
            if (color[i] == -1 && !dfs(graph,i,color,0)) { // Start with color 0
                return false; // Not bipartite
            }

        }
        return true;

        
        
    } 
};
