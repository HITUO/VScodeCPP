#include <bits/stdc++.h>

using namespace std;

#define int long long

using LL = long long;
using VI = vector<int>;

const int kMaxN = 2e5 + 7;

int n, a[kMaxN], ans[kMaxN], s[kMaxN], r, cnt, cov;

signed main() {
  freopen("middle.in", "r", stdin);
  freopen("middle.out", "w", stdout);
  srand(time(0));
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    s[a[i]] = i;
  }
  for (int i = 1; i <= n; i++) {
    r = max(r, s[a[i]]);
    if (cov > i) {
      cnt++;
    } else {
      cov = r;
    }
  }
  cout << cnt;
  // for (int i = 1; i <= n; i++) {
  //   cout << ans[i] << " ";
  // }
  return 0;
}