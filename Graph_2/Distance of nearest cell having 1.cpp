    vector<int>dx{1,-1,0,0};
    vector<int>dy{0,0,1,-1};
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    //take a queue like {{i,j},dist}
	    queue<pair<pair<int,int>,int>>q;
	    int n=grid.size();
	    int m=grid[0].size();
	    //take a visited array 
	    vector<vector<int>>vis(n,vector<int>(m,0));
	    //take ans array
	    vector<vector<int>>ans(n,vector<int>(m,0));
	  for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(grid[i][j]==1){
	                vis[i][j]=1;
	                q.push({{i,j},0});
	                ans[i][j]=0;
	            }
	        }
	    }
	    //take a bfs traversal
	        while(!q.empty()){
	        int i=q.front().first.first;
	        int j=q.front().first.second;
	        int dist=q.front().second;
	        ans[i][j]=dist;
	        q.pop();
	        for(int k=0;k<4;k++){
	            int x=i+dx[k];
	            int y=j+dy[k];
	            if(x<n && y<m && x>=0 && y>=0 && vis[x][y]==0){
	                 vis[x][y]=1;
	                 q.push({{x,y},dist+1});
	            }
	        }
	        
	    }
	
	    return ans;
	}
