int minimumEdgeReversal(vector<vector<int>> &edges,int n,int src,int dst)
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
                    
                      
        }
