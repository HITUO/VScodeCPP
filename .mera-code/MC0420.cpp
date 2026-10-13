#include <bits/stdc++.h>

using namespace std;

#define int long long

using LL = long long;
using VI = vector<int>;

const int kMaxN = 1e2 + 7;

int n, m, a[kMaxN][kMaxN], f[kMaxN][kMaxN], g[kMaxN][kMaxN];

signed main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  memset(f, 0, sizeof f);
  cin >> n >> m;
  // for (int i = 1; i <= n; i++) {
  //     for (int j = 1; j <= m; j++) {
  //         cout << f[i][j] << " ";
  //     }
  //     cout << "\n";
  // } cout << "\n";
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
      // cout << f[i - 1][i] << "  " << f[i][j - 1] << "  " << a[i][j] << " ";
      f[i][j] = f[i - 1][j] + f[i][j - 1] + a[i][j] - f[i - 1][j - 1];
      g[i][j] = f[i][j] / i / j;
    }
  }
  // for (int i = 1; i <= n; i++) {
  //     for (int j = 1; j <= m; j++) {
  //         cout << f[i][j] << " ";
  //     }
  //     cout << "\n";
  // } cout << "\n";
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cout << g[i][j] << " ";
    }
    cout << "\n";
  }
  return 0;
}