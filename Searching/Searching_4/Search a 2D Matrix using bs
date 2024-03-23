class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int m=mat.size();
        int n=mat[0].size();
        int start=0;
        int end=m*n-1;
        while(start<=end){
            int mid=(start+end)>>1;
            int row = mid / n;
            int col = mid % n;
            if(mat[row][col]==target){
                return true;
            }else if(mat[row][col]>target){
                end=mid-1;
            }else{
                start=mid+1;
            }
        }
        return false;
    }
};
