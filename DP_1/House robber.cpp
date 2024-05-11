class Solution {
public:
    int rob(vector<int>& nums) {
        ///DP APPORACH
        int n=nums.size();
       if(n==0)return 0;
        vector<int>dp(n+1,0);
        dp[0]=nums[0];
        if(n==1)return dp[0];
        dp[1]=max(nums[0],nums[1]);
      

        // 2 7 11 11 12
        for(int i=2;i<n;i++){
            dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
            
        }
        return dp[n-1];
        
    }
};
/*int helper(vector<int>& nums, int idx, vector<int>& memo) {
        if (idx >= nums.size()) return 0;
        
        if (memo[idx] != -1) return memo[idx];
        
        int robCur = nums[idx] + helper(nums, idx + 2, memo);
        int skipCur = helper(nums, idx + 1, memo);
        
        memo[idx] = max(robCur, skipCur);
        
        return memo[idx];
    }*/
