
	public:
	//Function to find number of strongly connected components in the graph.
	void dfs(vector<vector<int>>&adj,stack<int>&st,vector<int>&vis,int i){
	    vis[i]=1;
	    for(auto u:adj[i]){
	        if(!vis[u]){
	            dfs(adj,st,vis,u);
	        }
	    }
	    st.push(i);
	}
	void df(vector<vector<int>>&ad,vector<int>&vis,int i){
	    vis[i]=1;
	    for(auto u:ad[i]){
	        if(!vis[u]){
	            df(ad,vis,u);
	        }
	    }
	   
	}
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //step1->make a topo stack
        stack<int>st;
        vector<int>vis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(adj,st,vis,i);
            }
        }
        //reverse the node of graph
        vector<vector<int>>ad;
        for(int i=0;i<V;i++){
           for(auto u:adj[i]){
               ad[u].push_back(i);
           }
        }
        //ab last stage stack ke acc dfs called
        for(int i=0;i<V;i++)vis[i]=0;
        int cnt=0;
        while(!st.empty()){
            int x=st.top();
            st.pop();
            if(!vis[x]){
                df(ad,vis,x);
                cnt++;
            }
        }
        
        return cnt;
    }
};
