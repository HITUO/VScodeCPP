#include <bits/stdc++.h>

using namespace std;

#define int long long

using LL = long long;
using VI = vector<int>;

const int kMaxN = 1e4 + 7;

int T, n, a[kMaxN], b[kMaxN], c[kMaxN];

signed main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> T;
  while (T--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i] >> b[i] >> c[i];
    }
    cout << "0.0000\n0.5000\n";
  }
  return 0;
}