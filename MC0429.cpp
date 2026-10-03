#include <bits/stdc++.h>

using namespace std;

#define int long long

using LL = long long;
using VI = vector<int>;

const int kMaxN = 5e3 + 7, kMoD = 998244353;

int n, dp[kMaxN][kMaxN];
string s;

signed main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> s;
  s = '#' + s;
  for (int i = 1; i <= n; i++) {
    dp[i][i] = 1;
  }
  for (int len = 2; len <= n; len++) {
    for (int i = 1; i + len - 1 <= n; i++) {
      int j = i + len - 1;
      if (s[i] == s[j]) {
        (dp[i][j] = dp[i][j - 1] + dp[i + 1][j] + 1) %= kMoD;
      } else {
        (dp[i][j] = dp[i][j - 1] + dp[i + 1][j] - dp[i + 1][j - 1] + kMoD) %=
            kMoD;
      }
    }
  }
  cout << dp[1][n] % kMoD;
  return 0;
}