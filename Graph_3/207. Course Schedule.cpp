class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //create adj list if topo possible 
        //topo sirf dag ka possible hai
        unordered_map<int,vector<int>>adj;
        int n=numCourses;
        for(int i=0;i<prerequisites.size();i++)  {
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];
            adj[u].push_back(v);
        }
        //code for topo
        vector<int>id(n,0);
        for(int i=0;i<n;i++){
            for(auto u:adj[i]){
                id[u]++;
            }
        }
        queue<int>q;
           for(int i=0;i<n;i++){
            if(id[i]==0){
                q.push(i);//0 vala push
            }
        }
        int cnt=0;
        while(!q.empty()){
            int v=q.front();
            q.pop();
            cnt++;
            for(auto u:adj[v]){
                id[u]--;
                if(id[u]==0)q.push(u);
            }
        }
        if(cnt==n)return true;
        return false;
    }
};
