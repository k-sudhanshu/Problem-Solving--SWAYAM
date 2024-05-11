class Solution {
public:
    int numSquares(int n) {
        //vector for updating the dp array/values
        vector<int> dp(n+1,INT_MAX);
        //base case
        dp[0]=0;
        int count = 1;
        while(count*count <= n) {
        int sq = count*count;
        for(int i = sq; i < n+1; i++) {
            dp[i] = min(dp[i-sq] + 1,dp[i]);
        }
        count++;
    }
    return dp[n];
    }
};
/* int helper(int n,vector<int>& dp) {
        if (n <= 0) return 0;
        if (dp[n] != INT_MAX) return dp[n];
        
        int sqrt_n = sqrt(n);
        for (int i = 1; i <= sqrt_n; ++i) {
            int square = i * i;
            dp[n] = std::min(dp[n], helper(n - square, dp) + 1);
        }
        
        return dp[n];
    }*/
