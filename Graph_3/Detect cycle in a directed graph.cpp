bool isCyclic(int V, vector<int> adj[]) {
        //cycle ke liye cheack kar lete hai agr topo nikal pate hai;
        //sabse pahle indgree
        vector<int>indegree(V,0);
        for(int i=0;i<V;i++){
            for(auto u:adj[i]){
                indegree[u]++;
            }
        }
        queue<int>q;
        int cnt=0;
        for(int i=0;i<V;i++){
            if(indegree[i]==0)q.push(i);
        }
        while(!q.empty()){
            int u=q.front();
            q.pop();
            cnt++;
            for(auto v:adj[u]){
                indegree[v]--;
                if(indegree[v]==0){
                    q.push(v);
                }
            }
        }
        if(cnt==V)return false;
        return true;
    }
