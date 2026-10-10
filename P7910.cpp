#include <bits/stdc++.h>

using namespace std;

#define int long long

using LL = long long;
using VI = vector<int>;

const int kMaxN = 8e4 + 7;

int n, q, a[kMaxN];

signed main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int T = 1; T <= q; T++) {
    int opt;
    cin >> opt;
    if (opt == 1) {
      int x, v;
      cin >> x >> v;
      a[x] = v;
    } else {
      int x;
      cin >> x;
      int cnt = 1;
      for (int i = 1; i < x; i++) {
        if (a[x] >= a[i]) {
          cnt++;
        }
      }
      for (int i = x + 1; i <= n; i++) {
        if (a[x] > a[i]) {
          cnt++;
        }
      }
      cout << cnt << "\n";
    }
  }
  return 0;
}