
/*
class Solution {
public:
int solve(vector<int>&nums,int i,int p){
    int n=nums.size();
    if(i>=n)return 0;
    int take=0;
    if(p==-1 or nums[p]<nums[i])take=1+solve(nums,i+1,i);
    int nottake=solve(nums,i+1,p);
    return max(take,nottake);
}
    int lengthOfLIS(vector<int>& nums) {
        return solve(nums,0,-1);
    }
};
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        //[0,1,0,3,2,3]
        //0 2 3 
        //[10,9,2,5,3,7,101,18]
        //2 5 18 101
        //binary search sol idea is
        int n=nums.size();
        vector<int>v;
        v.push_back(nums[0]);
        for(int i=1;i<n;i++){
            if(nums[i]>v.back()){
                v.push_back(nums[i]);
            }
            else{
                int x=lower_bound(v.begin(),v.end(),nums[i])-v.begin();
                v[x]=nums[i];
            }
        }
        int ans=v.size();
        return ans;
    }
};
*/class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1);
        dp[0]=1;
        for(int i=1;i<n;i++){
            int cnt=1;
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    cnt=max(dp[j]+1,cnt);
                }
            }
          dp[i]=cnt;
        }
         int ans=1;
      for(auto i:dp){
          ans=max(i,ans);
      }
        return ans;
    }
};
