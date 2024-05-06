class Solution{
    public:
        int minimumEdgeReversal(vector<vector<int>> &edges,int n,int src,int dst)
        {
            //idea hai ki mai new adjany list bana lu and is adjancany list 
            // a--->b agr exist karta hai to 0 weight
           
        vector<vector<vector<int>>>adj(n+1);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            //ye to exist karega hi 
            //isliye dist 0 kch is tarah {u->v,0}
            adj[u].push_back({v,0});
            //ye revese direction miya hu
            adj[v].push_back({u,1});
        }
        //ab diskastra algoritm laga raha hu sc to desti minimum ;patha kya hoga
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        q.push({0,src});
        //take a minimum path array for each point
       vector<int>d(n+1,INT_MAX);
       d[src]=0;
       while(!q.empty()){
           int node=q.top().second;
           int dis=q.top().first;
           q.pop();
           for(auto u:adj[node]){
               int x=u[1];
               int v=u[0];
               if(x+dis<d[v]){
                   d[v]=x+dis;
                    q.push({d[v],v});
               }
           }
       }
        if(d[dst]==INT_MAX)return -1;
         return d[dst];
       
    
                      
        }
//2nd way
/*int minimumEdgeReversal(vector<vector<int>> &edges,int n,int src,int dst)
        {
            //making a model graph with weighted graph
            vector<vector<pair<int,int>>> adj(n+1);
            for(vector<int> &e:edges)
            {
                int u=e[0];
                int v=e[1];
                
                adj[u].push_back({v,0});//original wt 0
                adj[v].push_back({u,1});
                
            }
            
            set<pair<int,int>>setds;
            vector<int> dist(n+1,INT_MAX);
            setds.insert(make_pair(0,src));
            dist[src]=0;
            
            while(!setds.empty())
            {
                pair<int,int> tmp =*(setds.begin());
                setds.erase(setds.begin());
                int u=tmp.second;
                for(auto e:adj[u])
                {
                    int v=e.first;
                    int wt=e.second;
                    if(dist[v]>dist[u]+wt)
                    {
                        if(dist[v]!=INT_MAX)
                        {
                            setds.erase(setds.find(make_pair(dist[v],v)));
                        }
                        dist[v]=dist[u]+wt;
                        setds.insert({dist[v],v});
                    }
                }
            }
            if(dist[dst]==INT_MAX) return -1;
            
            else return dist[dst];
                                
        }*/
