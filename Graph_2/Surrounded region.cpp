class Solution {
public:
//for direction
int n,m;
vector<int>x{0,0,1,-1};
vector<int>y{1,-1,0,0};
void dfs(int i,int j,vector<vector<char>>&board){
    n=board.size();
       m=board[0].size();
    if( i<0 or j<0 or i>=n or j>=m or board[i][j]!='O' )return;
    board[i][j]='#';
    for(int k=0;k<4;k++){
        dfs(i+x[k],j+y[k],board);
    }
}

    void solve(vector<vector<char>>& board) {
    //step-> boundry pe jaha 0 mil raha hai usase dfs kar ke sabko alag value bana lo 
    //uske baad jo 1 bach gaya use 0 mai convert kar do

       n=board.size();
       m=board[0].size();
     if (board.empty()) return;
       for(int i=0;i<n;i++){
            if(board[i][0]=='O'){
              dfs(i,0,board);
            }
            if(board[i][m-1]=='O'){
                dfs(i,m-1,board);
            }
       }
        for(int i=0;i<m;i++){
            if(board[0][i]=='O'){
              dfs(0,i,board);
            }
            if(board[n-1][i]=='O'){
                dfs(n-1,i,board);
            }
       }
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]=='O'){
                board[i][j]='X';
            }
        }
       }
          for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]=='#'){
                board[i][j]='O';
            }
        }
       }
        
    }
};
