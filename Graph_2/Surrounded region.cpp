class Solution {
public:
    void dfs(int r, int c, vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        if (r < 0 || r >= n || c < 0 || c >= m || board[r][c] != 'O') {
            return;
        }
        board[r][c] = '#';
        dfs(r - 1, c, board);
        dfs(r + 1, c, board);
        dfs(r, c + 1, board);
        dfs(r, c - 1, board);
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        
        for (int i = 0; i < m; i++) {
            if (board[0][i] == 'O') {
                dfs(0, i, board);
            }
            if (board[n - 1][i] == 'O') {
                dfs(n - 1, i, board);
            }
        }

        for (int j = 0; j < n; j++) {
            if (board[j][0] == 'O') {
                dfs(j, 0, board);
            }
            if (board[j][m - 1] == 'O') {
                dfs(j, m - 1, board);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
               if (board[i][j] == '#') {
                    board[i][j] = 'O';
                }
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
               
            }
        }
    }
};
