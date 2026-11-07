#include <bits/stdc++.h>

using namespace std;

#define int long long

using LL = long long;
using VI = vector<int>;

const int kMaxN = 1e3 + 7;

int n, w[kMaxN], d[kMaxN], maxn = LLONG_MIN, minn = LLONG_MAX, f[kMaxN][kMaxN];

signed main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> w[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> d[i];
  }
  int t = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (w[i] > d[j]) {
        f[i][j] = 2;
      } else if (w[i] == d[j]) {
        f[i][j] = 1;
      } else {
        f[i][j] = 0;
      }
    }
  }
  // int k = 0;
  // for (int i = 1; i <= n; i++) {
  //   k += f[i][i];
  // }
  // cout << "k = " << k << "\n";
  // maxn = max(maxn, k);
  // minn = min(minn, k);
  // for (int i = 0; i < n; i++) {
  //   int t = 0;
  //   for (int j = 1; j <= n; j++) {
  //     int kk = (i + j) % (n + 1) + 1;
  //     t += f[j][kk];
  //   }
  //   cout << "i = " << i << "   t = " << t << "\n";
  //   maxn = max(maxn, t);
  //   minn = min(minn, t);
  // }
  for (int i = 1; i <= n; i++) {
    int t = 0;
    for (int j = 1; j <= n; j++) {
      t += f[i][j];
    }
    maxn = max(maxn, t);
    minn = min(minn, t);
  }
  cout << maxn << " " << minn;
  return 0;
}