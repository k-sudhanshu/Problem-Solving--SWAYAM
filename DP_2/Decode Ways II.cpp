//memery limit exceed sol
class Solution {
public:
   typedef long long ll;

ll ways(string s, int i, vector<ll> &dp) {
    if (i > s.size()) {
        return 0;
    }
    if (i == s.size()) {
        return 1;
    }
    if (s[i] == '0') {
        return 0;
    }

    if (dp[i] == -1) {
        ll a1 = ways(s, i + 1, dp);
        if (s[i] == '*') {
            a1 = a1 * 9;
        }
        ll a2 = 0;
        if (i + 1 < s.size()) {
            if (s[i] == '*' && s[i + 1] == '*') {
                a2 = 15 * ways(s, i + 2, dp);
            } else if ((s[i] == '1' || s[i] == '2') && s[i + 1] == '*') {
                a2 = (s[i] == '1' ? 9 : 6) * ways(s, i + 2, dp);
            } else if (s[i] == '*' && s[i + 1] - '0' <= 6) {
                a2 = 2 * (ways(s, i + 2, dp));
            } else if ((s[i] == '1' && s[i + 1] - '0' <= 9) || (s[i] == '2' && s[i + 1] - '0' <= 6)) {
                a2 = ways(s, i + 2, dp);
            } else if (s[i] == '*') {
                a2 = ways(s, i + 2, dp);
            }
        }
        dp[i] = (a1 + a2) % 1000000007;
    }
    return dp[i];
}

int numDecodings(string s) {
    vector<ll> dp(s.size() + 1, -1);
    return (int)ways(s, 0, dp);
}
};
