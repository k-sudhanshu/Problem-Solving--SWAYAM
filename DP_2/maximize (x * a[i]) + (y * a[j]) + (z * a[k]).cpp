/*Input : arr[] = {-1, -2, -3, -4, -5} 
         x = 1 
         y = 2 
         z = -3 
Output: 12
Explanation: The maximized values is 
(1 * -1) + (2 * -1) + ( -3 * -5) = 12 

Input: arr[] = {1, 2, 3, 4, 5} 
       x = 1 
       y = 2  
       z = 3 
Output: 30 
(1*5 + 2*5 + 3*5) = 30
*/

int maxExpr(int a[], int n, int x, int y, int z) 
{ 
    int L[n]; 
    L[0] = x * a[0]; 
    for (int i = 1; i < n; i++) 
        L[i] = max(L[i - 1], x * a[i]); 

    int R[n]; 
    R[n-1] = z * a[n-1]; 
    for (int i = n - 2; i >= 0; i--) 
        R[i] = max(R[i + 1], z * a[i]); 

    int ans = INT_MIN; 
    for (int i = 0; i < n; i++) 
        ans = max(ans, L[i] + y * a[i] + R[i]); 

    return ans; 
} 
