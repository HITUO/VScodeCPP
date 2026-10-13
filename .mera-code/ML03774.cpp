#include <bits/stdc++.h>

using namespace std;

#define int long long

using LL = long long;
using VI = vector<int>;

const int kMaxN = 2e5 + 7, INF = (1LL << 62);

struct SegTree {
  int n;
  VI mn;

  SegTree(int n = 0) { init(n); }

  void init(int n_) {
    n = n_;
    mn.assign(4 * n + 7, INF);
  }

  void build(int idx, int l, int r, VI &arr) {
    if (l == r) {
      mn[idx] = arr[l];
      return;
    }
    int mid = (l + r) / 2;
    build(idx * 2, l, mid, arr);
    build(idx * 2 + 1, mid + 1, r, arr);
    mn[idx] = min(mn[idx * 2], mn[idx * 2 + 1]);
  }

  void update(int idx, int l, int r, int pos, int val) {
    if (l == r) {
      mn[idx] = val;
      return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid) {
      update(idx * 2, l, mid, pos, val);
    } else {
      update(idx * 2 + 1, mid + 1, r, pos, val);
    }
    mn[idx] = min(mn[idx * 2], mn[idx * 2 + 1]);
  }

  int query(int idx, int l, int r, int ql, int qr) {
    if (ql > r || qr < l) {
      return INF;
    }
    if (ql <= l && r <= qr) {
      return mn[idx];
    }
    int mid = (l + r) / 2;
    return min(query(idx * 2, l, mid, ql, qr),
               query(idx * 2 + 1, mid + 1, r, ql, qr));
  }

  void build(VI &arr) { build(1, 1, n, arr); }

  void update(int pos, int val) { update(1, 1, n, pos, val); }

  int query(int l, int r) { return query(1, 1, n, l, r); }
};

signed main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n, q;
  cin >> n >> q;
  VI p(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
  }
  VI lefta(n + 1), righta(n + 1);
  for (int i = 1; i <= n; i++) {
    lefta[i] = p[i] - i;
    righta[i] = p[i] + i;
  }
  SegTree lefttree(n), righttree(n);
  lefttree.build(lefta);
  righttree.build(righta);
  while (q--) {
    int tt;
    cin >> tt;
    if (tt == 1) {
      int k, x;
      cin >> k >> x;
      p[k] = x;
      lefttree.update(k, x - k);
      righttree.update(k, x + k);
    } else {
      int k;
      cin >> k;
      int leftbest = lefttree.query(1, k), rightbest = righttree.query(k, n);
      int ans = min(leftbest + k, rightbest - k);
      cout << ans << "\n";
    }
  }
  return 0;
}