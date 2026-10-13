#include <bits/stdc++.h>

using namespace std;

using LL = long long;

const int kMaxN = 100005;

int n, m;
LL p;
LL a[kMaxN];

struct Node {
  LL sum;
  LL mul;
  LL add;
} tree[kMaxN << 2];

void build(int node, int l, int r) {
  tree[node].mul = 1;
  tree[node].add = 0;
  if (l == r) {
    tree[node].sum = a[l] % p;
    return;
  }
  int mid = (l + r) >> 1;
  build(node << 1, l, mid);
  build(node << 1 | 1, mid + 1, r);
  tree[node].sum = (tree[node << 1].sum + tree[node << 1 | 1].sum) % p;
}

void pushdown(int node, int l, int r) {
  if (tree[node].mul == 1 && tree[node].add == 0)
    return;
  int mid = (l + r) >> 1;
  int left = node << 1, right = node << 1 | 1;
  LL mul = tree[node].mul, add = tree[node].add;
  tree[left].sum = (tree[left].sum * mul + add * (mid - l + 1)) % p;
  tree[left].mul = (tree[left].mul * mul) % p;
  tree[left].add = (tree[left].add * mul + add) % p;
  tree[right].sum = (tree[right].sum * mul + add * (r - mid)) % p;
  tree[right].mul = (tree[right].mul * mul) % p;
  tree[right].add = (tree[right].add * mul + add) % p;
  tree[node].mul = 1;
  tree[node].add = 0;
}

void update(int node, int l, int r, int ql, int qr, int type, LL val) {
  if (ql <= l && r <= qr) {
    if (type == 1) {
      tree[node].sum = (tree[node].sum * val) % p;
      tree[node].mul = (tree[node].mul * val) % p;
      tree[node].add = (tree[node].add * val) % p;
    } else {
      tree[node].sum = (tree[node].sum + val * (r - l + 1)) % p;
      tree[node].add = (tree[node].add + val) % p;
    }
    return;
  }
  pushdown(node, l, r);
  int mid = (l + r) >> 1;
  if (ql <= mid)
    update(node << 1, l, mid, ql, qr, type, val);
  if (qr > mid)
    update(node << 1 | 1, mid + 1, r, ql, qr, type, val);
  tree[node].sum = (tree[node << 1].sum + tree[node << 1 | 1].sum) % p;
}

LL query(int node, int l, int r, int ql, int qr) {
  if (ql <= l && r <= qr) {
    return tree[node].sum;
  }
  pushdown(node, l, r);
  int mid = (l + r) >> 1;
  LL res = 0;
  if (ql <= mid)
    res = (res + query(node << 1, l, mid, ql, qr)) % p;
  if (qr > mid)
    res = (res + query(node << 1 | 1, mid + 1, r, ql, qr)) % p;
  return res;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> p;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  build(1, 1, n);
  cin >> m;
  while (m--) {
    int opt, t, g;
    LL c;
    cin >> opt;
    if (opt == 1) {
      cin >> t >> g >> c;
      update(1, 1, n, t, g, 1, c % p);
    } else if (opt == 2) {
      cin >> t >> g >> c;
      update(1, 1, n, t, g, 2, c % p);
    } else {
      cin >> t >> g;
      cout << query(1, 1, n, t, g) << '\n';
    }
  }
  return 0;
}