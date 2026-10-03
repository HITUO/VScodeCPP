#include <bits/stdc++.h>

using namespace std;

#define int long long

using LL = long long;
using VI = vector<int>;

const int kMaxN = 1e6 + 7, kMoD = 998244353;

int lowbit(int x) { return x & (-x); }

int n, q, sum = 0, a[kMaxN], cnt = 0;

signed main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    (sum += a[i]) %= kMoD;
  }
  for (int i = 1; i <= q; i++) {
    int opt;
    cin >> opt;
    if (opt == 1) {
      if (cnt <= 30) {
        sum = 0;
        for (int i = 1; i <= n; i++) {
          a[i] += lowbit(a[i]);
          (sum += a[i]) %= kMoD;
        }
      } else {
        (sum <<= 1) %= kMoD;
      }
      cnt++;
    } else {
      cout << sum % kMoD << "\n";
    }
  }
  return 0;
}