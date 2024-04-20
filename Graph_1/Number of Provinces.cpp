class Solution {
public:
void dfs(unordered_map<int,vector<int>>&adj,vector<int>&vis,int u){
    vis[u]=1;
    for(auto v:adj[u]){
        if(!vis[v])dfs(adj,vis,v);
    }
}
    int findCircleNum(vector<vector<int>>& mp) {
        //we change map into adj list then take dfs call and calculate disconnected
        
        unordered_map<int,vector<int>>adj;
        for(int i=0;i<mp.size();i++){
            for(int j=0;j<mp[0].size();j++){
                if(mp[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);

                }
            }
        }
        int n=adj.size();
        int ans=0;
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(adj,vis,i);
            ans++;
            }
        }
        return ans;
        
    }
};
