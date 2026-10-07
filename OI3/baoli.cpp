#include <bits/stdc++.h>

#define int long long

using namespace std;

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k, p;
  cin >> n >> k >> p;
  vector<int> a(n + 1), s(n + 2, 0);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    s[i] = s[i - 1] + a[i];
  }
  // for (auto i : s)
  //   cout << i << " ";
  // cout << "\n";
  int ans = 1e18;
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j++) {
      if ((s[j] - s[i]) % p >= k) {
        ans = min(ans, s[j] - s[i]);
      }
    }
  }
  cout << ans << "\n";
  return 0;
}
