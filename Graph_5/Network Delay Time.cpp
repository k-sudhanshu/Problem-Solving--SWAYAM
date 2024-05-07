class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //source to desti ka 
        vector<vector<vector<int>>>adj(n+1);
        for(int i=0;i<times.size();i++){
            int u=times[i][0];
            int v=times[i][1];
            int w=times[i][2];
        adj[u].push_back({v,w});
        }
        vector<int>d(n+1,INT_MAX);
        //pair<int,int>
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        q.push({0,k});
        d[k]=0;
        while(!q.empty()){
            int u=q.top().second;
            int dis=q.top().first;
            if(dis<d[u])continue;
            q.pop();
            for(auto v:adj[u]){
                int node=v[0];
                int w=v[1];
                if(w+dis<d[node]){
                    d[node]=w+dis;
                    q.push({d[node],node});
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            cout<<d[i]<<" ";
            if(d[i]==INT_MAX)return -1;
            ans=max(ans,d[i]);
        }
        return ans;
    }
};
