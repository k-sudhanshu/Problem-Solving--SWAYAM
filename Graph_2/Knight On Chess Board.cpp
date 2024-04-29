//0 0
//dircton of knight
vector<int>dx{-2,-1,1,2,-2,-1,1,2};
vector<int>dy{1,2,2,1,-1,-2,-2,-1};

int Solution::knight(int A, int B, int C, int D, int E, int F) {
    //dfs//bfs
vector<vector<int>>vis(A+1,vector<int>(B+1,0));
int ans=0;
queue<pair<int,int>>q;
vis[C][D]=1;
q.push({C,D});
while(!q.empty()){
    int n=q.size();
    if(vis[E][F]==1)return ans;
    ans++;
    for(int k=0;k<n;k++){
    int x=q.front().first;
    int y=q.front().second;
    q.pop();
    for(int i=0;i<8;i++){
        if(x+dx[i]>0 && y+dy[i]>0 && x+dx[i]<=A && y+dy[i]<=B && vis[x+dx[i]][y+dy[i]]==0 ){
            vis[x+dx[i]][y+dy[i]]=1;
            q.push({x+dx[i],y+dy[i]});
        }
    }
    }
}
    return -1;
    
}
