#include <bits/stdc++.h>

using namespace std;

#define int long long

using LL = long long;
using VI = vector<int>;

const int kMaxN = 1e6 + 7;

int n, a[kMaxN];

signed main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int t = a[1], ans = 0, k = 1;
  for (int i = 2; i <= n; i++) {
    if (a[i] == (t ^ 1)) {
      k++;
    } else {
      k = 1;
    }
    t = a[i];
    ans = max(ans, k);
  }
  cout << ans;
  return 0;
}