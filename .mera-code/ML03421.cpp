#include <bits/stdc++.h>

using namespace std;

#define int long long

using LL = long long;
using VI = vector<int>;

const int kMaxN = 2e5 + 7;

struct V {
  int sum, pre, suf, sub;
};

class SegTree {
private:
  int n;
  vector<V> tree;

  V merge(V &left, V &right) {
    V res;
    res.sum = left.sum + right.sum;
    res.pre = max(left.pre, left.sum + right.pre);
    res.suf = max(right.suf, right.sum + left.suf);
    res.sub = max({left.sub, right.sub, left.suf + right.pre});
    return res;
  }

public:
  SegTree(VI &arr) {
    n = arr.size();
    tree.resize(n << 2);
    build(1, 0, n - 1, arr);
  }

  void build(int idx, int l, int r, VI &arr) {
    if (l == r) {
      int val = arr[l];
      tree[idx].sum = val;
      tree[idx].pre = max(0LL, val);
      tree[idx].suf = max(0LL, val);
      tree[idx].sub = max(0LL, val);
      return;
    }
    int mid = (l + r) >> 1;
    build(idx << 1, l, mid, arr);
    build((idx << 1) + 1, mid + 1, r, arr);
    tree[idx] = merge(tree[idx << 1], tree[idx << 1 | 1]);
  }

  void update(int pos, int val) { update(1, 0, n - 1, pos, val); }

  void update(int idx, int l, int r, int pos, int val) {
    if (l == r) {
      tree[idx].sum = val;
      tree[idx].pre = max(0LL, val);
      tree[idx].suf = max(0LL, val);
      tree[idx].sub = max(0LL, val);
      return;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid) {
      update(idx << 1, l, mid, pos, val);
    } else {
      update((idx << 1) + 1, mid + 1, r, pos, val);
    }
    tree[idx] = merge(tree[idx << 1], tree[idx << 1 | 1]);
  }

  int query() { return tree[1].sub; }
};

signed main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n, m;
  cin >> n >> m;
  VI a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  SegTree seg(a);
  while (m--) {
    int k, x;
    cin >> k >> x;
    k--;
    seg.update(k, x);
    cout << seg.query() << "\n";
  }
  return 0;
}