#include <bits/stdc++.h>

using namespace std;

#define int long long

using LL = long long;
using VI = vector<int>;

const int kMaxN = 2e5 + 7;

struct V {
  int l, r, d;
};

int n, m, k, t, ans;
VI a;
vector<V> b;

bool cmp(V x, V y) { return x.l < y.l; }

bool check(int x) {
  if (x == 0) {
    return 1;
  }
  int u = 0, ll = -1, rr = -1;
  for (auto v : b) {
    if (v.d > a[m - x]) {
      if (ll == -1) {
        ll = v.l;
        rr = v.r;
      } else if (v.l <= rr + 1) {
        rr = max(rr, v.r);
      } else {
        u += rr - ll + 1;
        ll = v.l;
        rr = v.r;
      }
    }
  }
  if (ll != -1) {
    u += rr - ll + 1;
  }
  return n + u + 1 <= t;
}

signed main() {
  freopen("traps.in", "r", stdin);
  freopen("traps.out", "w", stdout);
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> m >> n >> k >> t;
  a.resize(m);
  for (int i = 0; i < m; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  b.resize(k);
  for (int i = 0; i < k; i++) {
    cin >> b[i].l >> b[i].r >> b[i].d;
  }
  sort(b.begin(), b.end(), cmp);
  int l = 0, r = m;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (check(mid)) {
      ans = mid;
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  cout << ans;
  return 0;
}