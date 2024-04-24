class Solution {
public:
vector<int>x{1,-1,0,0};
vector<int>y{0,0,1,-1};
    int orangesRotting(vector<vector<int>>& grid) {
       int n=grid.size();
       int m=grid[0].size();
       int ans=0;
       int cnt=0;
       vector<vector<int>>vis(n,vector<int>(m,0));
      // {{i,j},time}
      queue<pair<pair<int,int>,int>>pq;
      for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==2){
                pq.push({{i,j},0});
                vis[i][j]=1;
            }
            if(grid[i][j]==1){
                cnt++;
            }
        }
      }
      while(!pq.empty()){
        int r=pq.front().first.first;
        int c=pq.front().first.second;
        int t=pq.front().second;
        pq.pop();
        ans=max(ans,t);
        for(int i=0;i<4;i++){
            int ru=r+x[i];
            int cu=c+y[i];
            if(ru<n && cu<m && ru>=0 && cu>=0 && vis[ru][cu]==0 && grid[ru][cu]==1 ){
                vis[ru][cu]=1;
                pq.push({{ru,cu},t+1});
                cnt--;
            }
        }
      }
      if(cnt==0)return ans;
      return -1;
  
        
    }
};
