class Solution {
public:
    bool searchMatrix(vector<vector<int>>& A, int k) {
       int n=A.size();
       int m=A[0].size();
       int i=0;
       int j=m-1;
       while(i<n && j>=0){
           if(A[i][j]==k){
               return true;
           }
           else if(A[i][j]>k){
               j--;
           }
           else{
               i++;
           }
       }
       return false;
       
        
    }
};
