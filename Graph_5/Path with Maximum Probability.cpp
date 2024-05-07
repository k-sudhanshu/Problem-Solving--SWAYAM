class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int src, int dst) {
        vector<vector<pair<int,double>>>adj(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            double w=succProb[i];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        priority_queue<pair<double,int>>q;
        q.push({1.0,src});
        vector<double>d(n,0.0);
        d[src]=1;
       while(!q.empty()){
        int u=q.top().second;
        double dis=q.top().first;
        q.pop();
        for(auto v:adj[u]){
            double w=v.second;
            int node=v.first;
            if(dis*w>d[node]){
                d[node]=dis*w;
                q.push({d[node],node});
            }
        }
       }

        for(auto i:d)cout<<i<<" ";
        return d[dst] ;

    }
};
