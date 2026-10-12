#include <bits/stdc++.h>

using namespace std;

#define int long long

using LL = long long;
using VI = vector<int>;

const int kMaxN = 2e5 + 7;

int T, n, k, a[kMaxN], vis[kMaxN], ans;

signed main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> T;
  while (T--) {
    cin >> n >> k;
    VI t;
    ans = 0;
    for (int i = 0; i < k; i++) {
      vis[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      if (a[i] < k) {
        if (vis[a[i]] == 1) {
          t.push_back(a[i]);
        } else {
          vis[a[i]] = 1;
        }
      } else {
        t.push_back(a[i]);
      }
    }
    if (n < k) {
      cout << -1 << "\n";
      continue;
    }
    sort(t.rbegin(), t.rend());
    for (int i = 1; i < k; i++) {
      while (t.back() < i) {
        t.pop_back();
      }
      if (vis[i] == 0) {
        ans += t.back() - i;
        t.pop_back();
      }
    }
    cout << ans << "\n";
  }
  return 0;
}