#include <bits/stdc++.h>

using namespace std;

#define int long long

using LL = long long;
using VI = vector<int>;

const int kMaxN = 2e5 + 7;

struct SegTree {
  int n;
  VI mn, mx, lazy;

  SegTree(int n)
      : n(n), mn(4 * n + 7, 0), mx(4 * n + 7, 0), lazy(4 * n + 7, 0) {}

  void apply(int idx, int val) {
    mn[idx] += val;
    mx[idx] += val;
    lazy[idx] += val;
  }

  void push(int idx) {
    if (lazy[idx] != 0) {
      apply(idx * 2, lazy[idx]);
      apply(idx * 2 + 1, lazy[idx]);
      lazy[idx] = 0;
    }
  }

  void update(int idx, int l, int r, int ql, int qr, int val) {
    if (ql <= l && r <= qr) {
      apply(idx, val);
      return;
    }
    push(idx);
    int mid = (l + r) / 2;
    if (ql <= mid) {
      update(idx * 2, l, mid, ql, qr, val);
    }
    if (qr > mid) {
      update(idx * 2 + 1, mid + 1, r, ql, qr, val);
    }
    mn[idx] = min(mn[idx * 2], mn[idx * 2 + 1]);
    mx[idx] = max(mx[idx * 2], mx[idx * 2 + 1]);
  }

  pair<int, int> get_min_max() { return {mn[1], mx[1]}; }
};

signed main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  SegTree st(n);
  for (int i = 0; i < n; i++) {
    int c, s;
    cin >> c >> s;
    if (s == 1) {
      st.update(1, 1, n, 1, c, 1);
    } else {
      st.update(1, 1, n, 1, c, -1);
    }
    auto [mn, mx] = st.get_min_max();
    if (mn >= 0) {
      cout << ">\n";
    } else if (mx <= 0) {
      cout << "<\n";
    } else {
      cout << "?\n";
    }
  }
  return 0;
}