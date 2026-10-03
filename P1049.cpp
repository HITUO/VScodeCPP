#include <bits/stdc++.h>

using namespace std;

#define int long long

using LL = long long;
using VI = vector<int>;

const int kMaxN = 3e1 + 7, kMaxM = 2e4 + 7;

int v, n, t[kMaxN], dp[kMaxM];

signed main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> v >> n;
  for (int i = 1; i <= n; i++) {
    cin >> t[i];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = v; j >= t[i]; j--) {
      dp[j] = max(dp[j], dp[j - t[i]] + t[i]);
    }
  }
  cout << v - dp[v];
  return 0;
}