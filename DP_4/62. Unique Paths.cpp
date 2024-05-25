class Solution {
public:
    int uniquePaths(int m, int n) {
        //m-n+2 C m-1
        //10C2  10*9 /2*1
        int a=m+n-2;
        int b=m-1;
        long long r=1;
        long long s=1;
         long long ans=1;
        for(int i=1;i<=b;i++){
            ans=ans*(a-b+i)/i;
        }
        
        return ans;
        
    }
};
class Solution {
    int count(int i,int j,int m,int n){
        if(i==m-1 &&  j==n-1 ) return 1;
         else if(i>=m or j>=n )return 0;
         else 
         {
         return count(i+1,j,m,n)+count(i,j+1,m,n);}
     }

public:
    int uniquePaths(int m, int n) {
         
     return count(0,0,m,n) ;   
        
    }
};
