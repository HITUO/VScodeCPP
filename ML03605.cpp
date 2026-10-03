#include <bits/stdc++.h>

using namespace std;

#define int long long

using LL = long long;
using VI = vector<int>;

const int kMaxN = 2e5 + 7, INF = 1e18;

int n, m;

struct SegTree {
  VI maxv, addv;

  SegTree() : maxv(4 * n + 4), addv(4 * n + 4) {}

  void pushdown(int o, int lc, int rc) {
    int &a = addv[o];
    if (a) {
      addv[lc] += a;
      addv[rc] += a;
      maxv[lc] += a;
      maxv[rc] += a;
      a = 0;
    }
  }

  void add(int o, int v) {
    maxv[o] += v;
    addv[o] += v;
  }

  void add(int ql, int qr, int v, int o = 1, int l = 0, int r = n + 1) {
    int mid = l + (r - l) / 2, lc = 2 * o, rc = 2 * o + 1;
    if (ql <= l && r <= qr) {
      return add(o, v);
    }
    pushdown(o, lc, rc);
    if (ql <= mid) {
      add(ql, qr, v, lc, l, mid);
    }
    if (qr > mid) {
      add(ql, qr, v, rc, mid + 1, r);
    }
    maxv[o] = max(maxv[lc], maxv[rc]);
  }

  int query(int ql, int qr, int o = 1, int l = 0, int r = n + 1) {
    int mid = l + (r - l) / 2, lc = 2 * o, rc = 2 * o + 1;
    if (ql <= l && r <= qr) {
      return maxv[o];
    }
    pushdown(o, lc, rc);
    return max(ql <= mid ? query(ql, qr, lc, l, mid) : -INF,
               qr > mid ? query(ql, qr, rc, mid + 1, r) : -INF);
  }
};

signed main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  SegTree st;
  map<int, vector<pair<int, int>>> q;
  for (int i = 0; i < m; i++) {
    int l, r, a;
    cin >> l >> r >> a;
    q[l].push_back({l, a});
    q[r + 1].push_back({l, -a});
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (q.count(i)) {
      for (auto &p : q[i]) {
        st.add(0, p.first - 1, p.second);
      }
    }
    int f = st.query(0, i - 1);
    st.add(i, i, f);
    ans = max(ans, f);
  }
  cout << ans << "\n";
  return 0;
}