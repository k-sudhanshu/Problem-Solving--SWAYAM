class Solution {
public:
    int maxProduct(vector<int>& A) {
        //dp as well as kaddne 
        int n=A.size();
        int maxp=A[0];
        int minp=A[0];
        int x,y;
        int ans=A[0];
        // 0 1 2 3 4 5
  //dp //  2 6 
        for(int i=1;i<n;i++){
            x=A[i]*maxp;
            y=A[i]*minp;
            maxp=max(A[i],max(x,y));
            minp=min(A[i],min(x,y));
            ans=max(ans,maxp) ;  
        }
        return ans;
    }
};
