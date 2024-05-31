#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& w, int s, int e, int y, vector<vector<int>>& dp) {
    if (s > e) return 0;

    if (dp[s][e] != -1) return dp[s][e];

    int sellStart = w[s] * y + maxProfit(w, s + 1, e, y + 1, dp);
    int sellEnd = w[e] * y + maxProfit(w, s, e - 1, y + 1, dp);

    dp[s][e] = max(sellStart, sellEnd);
    return dp[s][e];
}

int main() {
    int n;
    cin >> n;
    vector<int> w(n);
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
    }

    vector<vector<int>> dp(n, vector<int>(n, -1));
    cout << maxProfit(w, 0, n - 1, 1, dp) << endl;
    return 0;
}
