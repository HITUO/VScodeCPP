#include <bits/stdc++.h>

using namespace std;

#define int long long

using LL = long long;
using VI = vector<int>;

const int kMaxN = 2e5 + 7;

struct Segtree {
  int n;
  VI t;
  const int INF = 1e9;

  Segtree(int _n = 0) : n(_n), t(4 * n, INF) {}

  void update(int x, int val) { update(x, val, 1, 1, n); }

  void update(int x, int val, int o, int l, int r) {
    if (l == r) {
      t[o] = val;
      return;
    }
    int mid = (l + r) / 2;
    if (x <= mid) {
      update(x, val, o * 2, l, mid);
    } else {
      update(x, val, o * 2 + 1, mid + 1, r);
    }
    t[o] = min(t[o * 2], t[o * 2 + 1]);
  }

  int query(int ql, int qr) { return query(ql, qr, 1, 1, n); }

  int query(int ql, int qr, int o, int l, int r) {
    if (qr < l || r < ql) {
      return INF;
    }
    if (ql <= l && r <= qr) {
      return t[o];
    }
    int mid = (l + r) / 2;
    return min(query(ql, qr, o * 2, l, mid),
               query(ql, qr, o * 2 + 1, mid + 1, r));
  }
};

signed main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int n, q;
  cin >> n >> q;
  VI a(n + 1), next_arr(n + 1, n + 1);
  const int INF = n + 1;
  unordered_map<int, set<int>> pos;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    pos[a[i]].insert(i);
  }
  for (auto &p : pos) {
    auto &s = p.second;
    for (auto it = s.begin(); it != s.end(); it++) {
      auto it_next = next(it);
      if (it_next != s.end()) {
        next_arr[*it] = *it_next;
      } else {
        next_arr[*it] = INF;
      }
    }
  }
  Segtree tree(n);
  for (int i = 1; i <= n; i++) {
    tree.update(i, next_arr[i]);
  }
  while (q--) {
    int opt, x, y;
    cin >> opt >> x >> y;
    if (opt == 1) {
      int old = a[x];
      if (old == y) {
        continue;
      }
      auto &s_old = pos[old];
      auto it = s_old.find(x);
      int pre = -1, suc = INF;
      if (it != s_old.begin()) {
        pre = *prev(it);
      }
      if (next(it) != s_old.end()) {
        suc = *next(it);
      }
      if (pre != -1) {
        next_arr[pre] = suc;
        tree.update(pre, suc);
      }
      s_old.erase(it);
      if (s_old.empty()) {
        pos.erase(old);
      }
      auto &s_new = pos[y];
      s_new.insert(x);
      it = s_new.find(x);
      pre = -1, suc = INF;
      if (it != s_new.begin()) {
        pre = *prev(it);
      }
      if (next(it) != s_new.end()) {
        suc = *next(it);
      }
      if (pre != -1) {
        next_arr[pre] = x;
        tree.update(pre, x);
      }
      next_arr[x] = suc;
      tree.update(x, suc);
      a[x] = y;
    } else {
      int res = tree.query(x, y);
      if (res > y) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
    }
  }
  return 0;
}