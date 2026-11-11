#include <bits/stdc++.h>

using namespace std;

#define int long long

using LL = long long;
using VI = vector<int>;

const int kMaxN = 2e3 + 7;

int T, n, a[kMaxN], b[kMaxN], sum[kMaxN], ans;
bool vis[kMaxN];

bool is_f(int x) {
  double xx = sqrt(x * 1.0);
  return xx == (int)xx;
}

int you(int l, int r) { return sum[r - 1] - sum[l - 1]; }

void solve() {
  cin >> n;
  ans = INT_MAX;
  fill(vis, vis + n + 2, 0);
  fill(sum, sum + n + 2, 0);
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i];
    if (i > 1) {
      if (is_f(a[i] * b[i - 1])) {
        vis[i - 1] = 1;
      }
    }
  }
  for (int i = 1; i < n; i++) {
    sum[i] = sum[i - 1] + vis[i];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (is_f(a[i]) && is_f(b[i]) && you(i, j) == j - i) {
        ans = min(ans, j - i + 1);
      }
    }
  }
  if (ans == INT_MAX) {
    cout << "-1\n";
    return;
  }
  cout << ans << "\n";
}

signed main() {
  freopen("square.in", "r", stdin);
  freopen("square.out", "w", stdout);
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}