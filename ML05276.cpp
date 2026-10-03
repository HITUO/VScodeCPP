#include <bits/stdc++.h>

using namespace std;

#define int long long

using LL = long long;
using VI = vector<int>;

const int kMaxN = ((int)5e5 << 2) + 7;

int w, n, tree[kMaxN], lazy[kMaxN];

void build(int idx, int l, int r) {
  tree[idx] = 0;
  lazy[idx] = -1;
  if (l == r) {
    return;
  }
  int mid = (l + r) >> 1;
  build(idx << 1, l, mid);
  build(idx << 1 | 1, mid + 1, r);
}

void push_down(int idx) {
  if (~lazy[idx]) {
    int val = lazy[idx];
    tree[idx << 1] = val;
    lazy[idx << 1] = val;
    tree[idx << 1 | 1] = val;
    lazy[idx << 1 | 1] = val;
    lazy[idx] = -1;
  }
}

int query(int idx, int l, int r, int ql, int qr) {
  if (ql <= l && r <= qr) {
    return tree[idx];
  }
  push_down(idx);
  int mid = (l + r) >> 1, res = 0;
  if (ql <= mid) {
    res = max(res, query(idx << 1, l, mid, ql, qr));
  }
  if (qr > mid) {
    res = max(res, query(idx << 1 | 1, mid + 1, r, ql, qr));
  }
  return res;
}

void update(int idx, int l, int r, int ql, int qr, int val) {
  if (ql <= l && r <= qr) {
    tree[idx] = val;
    lazy[idx] = val;
    return;
  }
  push_down(idx);
  int mid = (l + r) >> 1;
  if (ql <= mid) {
    update(idx << 1, l, mid, ql, qr, val);
  }
  if (qr > mid) {
    update(idx << 1 | 1, mid + 1, r, ql, qr, val);
  }
  tree[idx] = max(tree[idx << 1], tree[idx << 1 | 1]);
}

signed main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> w >> n;
  build(1, 1, w);
  for (int i = 1; i <= n; i++) {
    int l, r;
    cin >> l >> r;
    int mh = query(1, 1, w, l, r), nh = mh + 1;
    cout << nh << "\n";
    update(1, 1, w, l, r, nh);
  }
  return 0;
}