class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
      //  [3,4,5,1,2]

        int s=0;
        int e=n-1;
        int ans=INT_MAX;
        while(s<e){
            int m=(s+e)/2;
            if(nums[m]>nums[e]){
                s=m+1;
            }
            else
                ans=min(ans,m);

        }
       return nums[ans];
    }
};
