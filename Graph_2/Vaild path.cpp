vector<int> dx{0,0,1,-1,1,-1,1,-1};
vector<int> dy{1,-1,0,0,-1,1,1,-1};
bool vaild(int i,int j,int x,int y,vector<vector<int>>&vis,int r,vector<int> &E, vector<int> &F){
    if(i<0 or j<0 or i>x or j>y or vis[i][j]==1)return 0;
    int n=E.size();
    for(int k=0;k<n;k++){
        int d=(E[k]-i)*(E[k]-i)+(F[k]-j)*(F[k]-j);
        if(d<=r*r){
            return false;}
    }
    return true;
}
void dfs(int i,int j,int x,int y,int r, vector<vector<int>>&vis,vector<int> &E, vector<int> &F){
    if(!vaild(i,j,x,y,vis,r,E,F))return;
    vis[i][j]=1;
    for(int k=0;k<8;k++){
        bool ch=vaild(i+dx[k],j+dy[k],x,y,vis,r,E,F);
        if(ch){
            dfs(i+dx[k],j+dy[k],x,y,r,vis,E,F);}
    }
}
string Solution::solve(int x, int y, int n, int r, vector<int> &E, vector<int> &F) {
    vector<vector<int>>vis((x+1),vector<int>(y+1,0));
    dfs(0,0,x,y,r,vis,E,F);
    if(vis[x][y]==1)return "YES";
    return "NO";
}
