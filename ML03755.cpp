#include <bits/stdc++.h>

using namespace std;

#define int long long

using LL = long long;
using VI = vector<int>;

const int kMaxN = 2e5 + 7;

int n, a[kMaxN], tree[kMaxN << 2];

void build(int idx, int l, int r) {
  if (l == r) {
    tree[idx] = 1;
    return;
  }
  int mid = (l + r) >> 1;
  build(idx << 1, l, mid);
  build(idx << 1 | 1, mid + 1, r);
  tree[idx] = tree[idx << 1] + tree[idx << 1 | 1];
}

void update(int idx, int l, int r, int pos) {
  if (l == r) {
    tree[idx] = 0;
    return;
  }
  int mid = (l + r) >> 1;
  if (pos <= mid) {
    update(idx << 1, l, mid, pos);
  } else {
    update(idx << 1 | 1, mid + 1, r, pos);
  }
  tree[idx] = tree[idx << 1] + tree[idx << 1 | 1];
}

int query(int idx, int l, int r, int k) {
  if (l == r) {
    return l;
  }
  int mid = (l + r) >> 1;
  if (k <= tree[idx << 1]) {
    return query(idx << 1, l, mid, k);
  } else {
    return query(idx << 1 | 1, mid + 1, r, k - tree[idx << 1]);
  }
}

signed main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  build(1, 1, n);
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    int pos = query(1, 1, n, x);
    cout << a[pos] << " \n"[i == n];
    update(1, 1, n, pos);
  }
  return 0;
}