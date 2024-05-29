/*class Solution {
public:
int min_edit(string s1,string s2,int i,int j){
     //base case
     if(i<0 && j<0)return 0;
     if(i<0)return j+1;
     if(j<0)return i+1;
if(s1[i]==s2[j]){
    return min_edit(s1,s2,i-1,j-1);
}
 int cost=1;
   int insert=min_edit(s1,s2,i,j-1)+cost;
   int delet=min_edit(s1,s2,i-1,j)+cost;
   int replac=min_edit(s1,s2,i-1,j-1)+cost;
   return min(insert,min(delet,replac));
}
    int minDistance(string s1, string s2) {
        int i=s1.size();
        int j=s2.size();
        return min_edit(s1,s2,i-1,j-1);
    }
};
class Solution {
public:
int ed(string a,string b,int n1,int n2,vector<vector<int>>dp){
    if(n1==0){
        return n2;
    }
    if(n2==0){
        return n1;
    }
     if(dp[n1][n2] !=-1)
        {
            return dp[n1][n2];
        }

    if(a[n1-1]==b[n2-1]){
          return dp[n1][n2]=ed(a,b,n1-1,n2-1,dp);
    }
    int x= 1+min(ed(a,b,n1-1,n2-1,dp),min(ed(a,b,n1,n2-1,dp),ed(a,b,n1-1,n2,dp)));
    return dp[n1][n2]=x;
}
    int minDistance(string word1, string word2) {
        int n1=word1.length();
        int n2=word2.length();
        //int dp[n1][m1+1];
         vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1));
        for(int i=0;i<=n1;i++){
            for(int j=0;j<=n2;j++){
                dp[i][j]=-1;
            }
        }
        return ed(word1,word2,n1,n2,dp);

    }
};
class Solution {
public:
    int minDistance(string a, string b) {
        int m=a.length();
        int n=b.length();
          vector<vector<int>>dp(m+1,vector<int>(n+1));
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(i==0)dp[i][j]=j;
            if(j==0)dp[i][j]=i;
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(a[i-1]==b[j-1]){
                dp[i][j]=dp[i-1][j-1];
            }
            else{
                int t=min(dp[i-1][j],dp[i][j-1]);
                dp[i][j]=1+min(t,dp[i-1][j-1]);}
            
        }
    }
    return dp[m][n];

        
    }
};*/
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++) {
            dp[i][0] = i;
        }
        for (int j = 1; j <= n; j++) {
            dp[0][j] = j;
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
                }
            }
        }
        return dp[m][n];
    }
};
