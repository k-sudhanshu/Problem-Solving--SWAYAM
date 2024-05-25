/*class Solution {
    int rows, cols;
    int calculateMinimumHPRecursive(int x, int y, vector<vector<int>>& dungeon) {
        if (x >= rows || x < 0 || y >= cols || y < 0)
            return INT_MIN;
        if (x == rows - 1 && y == cols - 1) return dungeon[x][y];
        int ans = dungeon[x][y];
        int value = dungeon[x][y] + max(calculateMinimumHPRecursive(x + 1, y, dungeon), calculateMinimumHPRecursive(x, y + 1, dungeon));
        return min(ans, value);
    }
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        rows = dungeon.size();
        cols = dungeon[0].size();
        int result = calculateMinimumHPRecursive(0, 0, dungeon);
        if (result >= 0)
            return 1;
        else {
            result = -1 * result;
            return result + 1;
        }
    }
};
*/




class Solution {
    int rows, cols;
    int dfs(int x, int y, vector<vector<int>>& dungeon, vector<vector<int>>& dp) {
        if (x >= rows || x < 0 || y >= cols || y < 0)
            return INT_MIN;
        if (x == rows - 1 && y == cols - 1) return dungeon[x][y];
        if (dp[x][y] != -1) return dp[x][y];
        int ans = dungeon[x][y];
        int value = dungeon[x][y] + max(dfs(x + 1, y, dungeon, dp), dfs(x, y + 1, dungeon, dp));
        return dp[x][y] = min(ans, value);
    }
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        rows = dungeon.size();
        cols = dungeon[0].size();
        vector<vector<int>> dp(rows + 1, vector<int>(cols + 1, -1));
        int result = dfs(0, 0, dungeon, dp);
        if (result >= 0)
            return 1;
        else {
            result = -1 * result;
            return result + 1;
        }
    }
};
