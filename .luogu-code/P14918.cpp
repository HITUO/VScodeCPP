#include <bits/stdc++.h>

using namespace std;

#define int long long

using LL = long long;
using VI = vector<int>;

const int kMaxN = 1e5 + 7;

int n, a[kMaxN];
VI c[kMaxN];

VI dec(int x) {
  int k = x;
  VI ret;
  int t = sqrt(k) + 1;
  for (int i = 2; i <= t; i++) {
    while (k % i == 0) {
      k /= i;
      ret.push_back(i);
    }
  }
  if (k > 1) {
    ret.push_back(k);
  }
  return ret;
}

signed main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    c[i] = dec(a[i]);
  }
  // for (int i = 1; i <= n; i++) {
  //   for (auto j : c[i]) {
  //     cout << j << " ";
  //   }
  //   cout << "\n";
  // }
  for (int i = 1; i <= n; i++) {
  }
  return 0;
} //