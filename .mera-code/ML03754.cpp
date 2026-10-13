#include <bits/stdc++.h>

using namespace std;

#define int long long

using LL = long long;
using VI = vector<int>;

const int kMaxN = 2e5 + 7;

int n, m, h[kMaxN], r[kMaxN], seg[kMaxN * 4];

void build(int idx, int l, int r) {
  if (l == r) {
    seg[idx] = h[l];
    return;
  }
  int mid = (l + r) / 2;
  build(idx * 2, l, mid);
  build(idx * 2 + 1, mid + 1, r);
  seg[idx] = max(seg[idx * 2], seg[idx * 2 + 1]);
}

void update(int idx, int l, int r, int pos, int val) {
  if (l == r) {
    seg[idx] -= val;
    return;
  }
  int mid = (l + r) / 2;
  if (pos <= mid) {
    update(idx * 2, l, mid, pos, val);
  } else {
    update(idx * 2 + 1, mid + 1, r, pos, val);
  }
  seg[idx] = max(seg[idx * 2], seg[idx * 2 + 1]);
}

int query(int idx, int l, int r, int x) {
  if (seg[idx] < x) {
    return -1;
  }
  if (l == r) {
    return l;
  }
  int mid = (l + r) / 2;
  int res = query(idx * 2, l, mid, x);
  if (~res) {
    return res;
  }
  return query(idx * 2 + 1, mid + 1, r, x);
}

signed main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> h[i];
  }
  for (int i = 1; i <= m; i++) {
    cin >> r[i];
  }
  build(1, 1, n);
  for (int i = 1; i <= m; i++) {
    int pos = query(1, 1, n, r[i]);
    cout << (~pos ? pos : 0) << " ";
    if (pos != -1) {
      update(1, 1, n, pos, r[i]);
    }
  }
  return 0;
}