class Solution {
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int t) {
         vector<int> dp(t + 1); 
    for(int i=0;i<=t;i++){dp[i]=-1;}
         dp[0] = 0; 
    for (int x : nums) { 
        for (int i = t; i >= x; i--) { 
            if (dp[i - x] != -1) { 
                dp[i] = max(dp[i], dp[i - x] + 1); 
            } 
        } 
    } 
 
    return dp[t]; 
         

        
    }
};
