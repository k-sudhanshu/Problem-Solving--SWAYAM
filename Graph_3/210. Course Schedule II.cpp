class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>&v) {
        //sabse pahle cheack topo possible hai ki nahi it 
        // 1--2
        //  \/
      
       unordered_map<int,vector<int>>adj;
       vector<int>ans;
       vector<int>id(n,0);
       for(int i=0;i<v.size();i++){
          int x=v[i][0];
          int y=v[i][1];
          adj[x].push_back(y);
          id[y]++;
       }
       queue<int>q;
       for(int i=0;i<n;i++){
           if(id[i]==0)q.push(i);
       }
       while(!q.empty()){
           int v=q.front();
           ans.push_back(v);
           q.pop();
           for(auto u:adj[v]){
            id[u]--;
            if(id[u]==0){
                q.push(u);
            }
           }
       }
       if(ans.size()!=n)return {};
       reverse(ans.begin(),ans.end());
      return ans;
        
    }
};
