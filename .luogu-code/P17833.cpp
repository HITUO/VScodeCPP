#include <bits/stdc++.h>

using namespace std;

#define int long long

using LL = long long;
using VI = vector<int>;

const int kMaxN = 2e6 + 7;

int n, d, c, t, a[kMaxN], cl[kMaxN], cr[kMaxN], nl[kMaxN], nr[kMaxN], l[kMaxN],
    r[kMaxN], ans, ll, rr;

signed main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> c >> t;
  while (t--) {
    fill(cl + 1, cl + n + 1, 0);
    fill(cr + 1, cr + n + 1, 0);
    ans = 0, rr = 1;
    cin >> n >> d;
    ll = n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
      while (rr + 1 <= n && a[rr + 1] - a[i] <= d) {
        rr++;
      }
      r[i] = rr;
      cl[rr]++;
    }
    for (int i = n; i >= 1; i--) {
      while (ll >= 2 && a[i] - a[ll - 1] <= d) {
        ll--;
      }
      l[i] = ll;
      cr[ll]++;
    }
    for (int i = 1; i <= n; i++) {
      nl[i] = cl[i];
      if (r[l[i]] == i) {
        nl[i] += nl[l[i]];
      }
    }
    for (int i = n; i >= 1; i--) {
      nr[i] = cr[i];
      if (l[r[i]] == i) {
        nr[i] += nr[r[i]];
      }
    }
    for (int i = 1; i <= n; i++) {
      if (r[i] - i > 1) {
        int j = r[r[i] - 1];
        if (l[j] != r[i] - 1) {
          continue;
        }
        int mnl, mnr;
        mnl = mnr = 0;
        if (l[r[i] - 1] == i) {
          mnl = nl[i];
        }
        if (r[r[i]] == j) {
          mnr = nr[j];
        }
        ans += (mnl + cl[r[i]]) * (mnr + cr[l[j]]);
        i += cl[r[i]] - 1;
      }
    }
    cout << ans << "\n";
  }
  return 0;
}