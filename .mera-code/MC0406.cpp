#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using VI = vector<int>;

#define int long long

const int kMaxN = 1e4 + 7, kMoD = 998244353;

int n, a[kMaxN], ans = 1;

int lcm(int x, int y) { return x * y / __gcd(x, y); }

signed main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    ans = lcm(ans, a[i]);
  }
  cout << ans % kMoD;
  return 0;
}