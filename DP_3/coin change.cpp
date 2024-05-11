class Solution {
public:
    int coinChange(vector<int>& a, int sum) {
        int n=a.size();
        vector<vector<int>>dp(n+1,vector<int>(sum+1));
        int x=INT_MAX-1;
         for(int i=0;i<=sum;i++)dp[0][i]=x;
        for(int i=0;i<=n;i++)dp[i][0]=0;
       
        for(int i=1;i<=sum;i++){
            if(i%a[0]==0){dp[1][i]=i/a[0];}
            else{
                dp[1][i]=x;
            } 
        }
        for(int i=2;i<=n;i++){
            for(int j=1;j<=sum;j++){
                if(a[i-1]>j){
                    dp[i][j]=dp[i-1][j];
                }
                else{
                    dp[i][j]=min(dp[i-1][j],dp[i][j-a[i-1]]+1);
                }
            }
        }
        if(dp[n][sum]==x)return -1;
       return dp[n][sum];
        
    }
};
