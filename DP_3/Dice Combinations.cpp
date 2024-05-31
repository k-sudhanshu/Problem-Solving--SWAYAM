#include <bits/stdc++.h>
using namespace std;

int sol(vector<int>& v, int n, vector<int>& memo) {
    if (n == 0) return 1;
    if (n < 0) return 0;

    if (memo[n] != -1) return memo[n];
    
    int count = 0;
    for (int i = 0; i < v.size(); ++i) {
        count += sol(v, n - v[i], memo);
    }
    
    memo[n] = count;
    return count;
}

int main() {
    int n;
    cin >> n;
    vector<int> v{1, 2, 3, 4, 5, 6};
    vector<int> memo(n + 1, -1); // Initialize memoization array with -1
    cout << sol(v, n, memo) << endl;
    return 0;
}
