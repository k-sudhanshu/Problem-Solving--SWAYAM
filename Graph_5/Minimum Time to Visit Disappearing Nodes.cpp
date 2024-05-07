class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        //ek kam kar sakte hai ki pahle min dis array bana lete hai for each pont usko compare kar lenge 
        //disapper arry se
    vector<vector<vector<int>>>adj(n);
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
        int w=edges[i][2];
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    //pair<int,int>
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
    q.push({0,0});
    vector<int>d(n,INT_MAX);
    d[0]=0;

    while(!q.empty()){
        int u=q.top().second;
        int dis=q.top().first;
        q.pop();
        if(dis>d[u])continue;
        for(auto v:adj[u]){
          int node=v[0];
          int w=v[1];
          //yaha dekh lete hai agr time khatm hai to aage nahi badh sakte hai uske help se
          if(dis+w<d[node] &&  disappear[node]-(dis+w)>0 ){
            d[node]=dis+w;
            q.push({d[node],node});
          }
        }
    }
    for(int i=0;i<n;i++){
         if(d[i]>disappear[i]){
            d[i]=-1;
        }
    }
    
    
    return d;

    }
};
