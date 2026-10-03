#include <bits/stdc++.h>

using namespace std;

#define int long long

using LL = long long;
using VI = vector<int>;

const int kMaxN = 2e5 + 7;

int n, m, w[kMaxN], v[kMaxN], dp[kMaxN];

signed main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> w[i] >> v[i];
    v[i] *= w[i];
  }
  for (int i = 1; i <= m; i++) {
    for (int j = n; j >= w[i]; j--) {
      dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
    }
  }
  cout << dp[n];
  return 0;
}