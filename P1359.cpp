#include <bits/stdc++.h>

using namespace std;

#define int long long

using LL = long long;
using VI = vector<int>;

const int kMaxN = 2e2 + 7;

int n, dp[kMaxN], r[kMaxN][kMaxN];

signed main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i < n; i++) {
    for (int j = i + 1; j <= n; j++) {
      cin >> r[i][j];
    }
  }
  memset(dp, 0x3f, sizeof dp);
  dp[1] = 0;
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j < i; j++) {
      dp[i] = min(dp[i], dp[j] + r[j][i]);
    }
  }
  cout << dp[n];
  return 0;
}