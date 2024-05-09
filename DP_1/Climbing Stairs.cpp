class Solution {
public:
    int climbStairs(int n) {
        //vector<int>dp(n+1);
        if(n==1)return 1;
        if(n==2)return 2;
        int x=1;
        int y=2;
        int z;
        
        for(int i=3;i<=n;i++){
           z=x+y;
           x=y;
           y=z;
        }
        return z;
    }
};
//apporach 2
class Solution {
public:
    int climbStairs(int n) {
        vector<int>dp(n+1);
        if(n==1)return 1;
        if(n==2)return 2;
        dp[1]=1;
        dp[2]=2;
        
        for(int i=3;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};
//apporach 3
class Solution {
public:
int cs(int n){
    if(n==1)return 1;
    if(n==2)return 2;
    return cs(n-1)+cs(n-2);
}
    int climbStairs(int n) {
        return cs(n);
        
    }
};
