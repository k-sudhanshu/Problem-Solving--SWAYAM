class Solution{
public:
   int maxSum(int N, vector<vector<int>> mat)
   {
       vector<int> dp(N+1, 0);
       dp[1] = max(mat[0][0], mat[1][0]);
       dp[2] = max(dp[1], max(mat[0][1], mat[1][1]));
       for(int i=3;i<=N;i++){
           int ans = max(mat[0][i-1], mat[1][i-1]);
           dp[i] = max(ans+dp[i-2], dp[i-1]);
       }
       return dp[N];
   }
};
