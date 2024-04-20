class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edge, int s, int d) {
        //pahle ek adjancy list bananana hai
        unordered_map<int,vector<int>>mp;
        for(auto i:edge){
            vector<int>temp=i;
            int u=temp[0];
            int v=temp[1];
            mp[u].push_back(v);
             mp[v].push_back(u);
        }
        vector<bool>vis(n+1,false);
        queue<int>q;
        q.push(s);
        vis[s]=true;
        while(!q.empty()){
            int x=q.front();
            q.pop();
            for(int i=0;i<mp[x].size();i++){
                if(vis[mp[x][i]]==false){
                    q.push(mp[x][i]);
                    vis[mp[x][i]]=true;
                }
            }
            if(vis[d]==true)return true;

        }
        return vis[d];
    }
};
