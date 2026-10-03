#include <bits/stdc++.h>

using namespace std;

#define int long long

using LL = long long;
using VI = vector<int>;

const int kMaxN = 1e3 + 7;

int n, m, dp[kMaxN], win[kMaxN], lose[kMaxN], use[kMaxN];

signed main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> lose[i] >> win[i] >> use[i];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = m; j >= use[i]; j--) {
      dp[j] = max(dp[j] + lose[i], dp[j - use[i]] + win[i]);
    }
    for (int j = use[i] - 1; j >= 0; j--) {
      dp[j] += lose[i];
    }
  }
  cout << 5 * dp[m];
  return 0;
}