class Solution
{
public:
    int countFriendsPairings(int n) 
    { 
        int mod=1e9+7;
        long long int dp[n+1];
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i]=(dp[i-1]+(i-1)*dp[i-2])%mod;
        }
        return dp[n];
        // code here
    }
}; 
