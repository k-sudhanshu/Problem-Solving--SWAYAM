/*
    int helper(int d, int f, int target, vector<vector<int>>& dp, int m) {
        if (d == 0 && target == 0)
            return 1;
        if (d == 0 || target <= 0)
            return 0;
        if (dp[d][target] != -1)
            return dp[d][target];

        int ways = 0;
        for (int k = 1; k <= f; k++) {
            if (k <= target)
                ways = (ways + helper(d - 1, f, target - k, dp, m)) % m;
        }

        dp[d][target] = ways;
        return ways;
    }
    int numRollsToTarget(int d, int f, int target) {
        int m = 1000000007;
        vector<vector<int>> dp(d + 1, vector<int>(target + 1, -1));
        return helper(d, f, target, dp, m);
    }
    

    int helper(int d, int f, int target, vector<vector<int>>& memo, int m) {
        if (d == 0 && target == 0)
            return 1;
        if (d == 0 || target <= 0)
            return 0;
        if (memo[d][target] != -1)
            return memo[d][target];

        int ways = 0;
        for (int k = 1; k <= f; k++) {
            if (k <= target)
                ways = (ways + helper(d - 1, f, target - k, memo, m)) % m;
        }

        memo[d][target] = ways;
        return ways;
    }

 int numRollsToTarget(int d, int f, int target) {
        int m = 1000000007;
        vector<vector<int>> memo(d + 1, vector<int>(target + 1, -1));
        return helper(d, f, target, memo, m);
    }
    };
    
    */
class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        int m=1000000007;
        vector<vector<int> > dp(d+1, vector<int>(target+1, 0));
        dp[0][0]=1;
        for(int i=1; i<=d; i++){
            for(int j=1; j<=target; j++){
                for(int k=1; k<=f; k++){
                    if(k<=j)
                        dp[i][j]=((dp[i][j]%m)+(dp[i-1][j-k]%m))%m;
                }
            }
        }
        return dp[d][target];
    }
};
