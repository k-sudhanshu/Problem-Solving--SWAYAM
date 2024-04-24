class Solution {
public:
vector<int>x{1,-1,0,0};
vector<int>y{0,0,1,-1};
void dfs(vector<vector<char>>&grid,vector<vector<int>>&vis,int i,int j){
    int n=grid.size();
      int m=grid[0].size();
      if(i<0 or j<0 or i>=n or j>=m or grid[i][j]=='0' or vis[i][j]==1)return;
      vis[i][j]=1;
      for(int k=0;k<4;k++){
        dfs(grid,vis,i+x[k],j+y[k]);
      }
}

    int numIslands(vector<vector<char>>& grid) {
        //dfs karna hai agar naya mile to cnt mai +1
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
    
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0 && grid[i][j]=='1'){
                    dfs(grid,vis,i,j);
                    ans++;
                }
            }
        }
        return ans;
    }
};
