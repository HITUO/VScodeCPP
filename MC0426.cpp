#include <bits/stdc++.h>

using namespace std;

#define int long long

using LL = long long;
using VI = vector<int>;

const int kMaxN = 2e5 + 7;

int T, n, q;

signed main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> T;
  while (T--) {
    cin >> n >> q;
    vector<VI> g(27, VI(27, LLONG_MAX / 2));
    for (int i = 1; i <= n; i++) {
      string s;
      cin >> s;
      g[(int)(s.front() - 'a' + 1)][(int)(s.back() - 'a' + 1)] = 1;
    }
    for (int k = 1; k <= 26; k++) {
      for (int i = 1; i <= 26; i++) {
        for (int j = 1; j <= 26; j++) {
          g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
        }
      }
    }
    for (int i = 1; i <= q; i++) {
      char x, y;
      int a, b;
      cin >> x >> y;
      a = (int)(x - 'a' + 1), b = (int)(y - 'a' + 1);
      if (g[a][b] != LLONG_MAX / 2) {
        cout << "Yes\n";
      } else {
        cout << "No\n";
      }
    }
  }
  return 0;
}