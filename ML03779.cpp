#include <bits/stdc++.h>

using namespace std;

#define int long long

using LL = long long;
using VI = vector<int>;

const int kMaxN = 2e5 + 7;

struct Node {
  int sum;
  int add;
  int addi;
};

vector<Node> tree;
int n, q;

void build(int idx, int l, int r, const vector<int> &a) {
  if (l == r) {
    tree[idx].sum = a[l];
    return;
  }
  int mid = (l + r) / 2;
  build(idx * 2, l, mid, a);
  build(idx * 2 + 1, mid + 1, r, a);
  tree[idx].sum = tree[idx * 2].sum + tree[idx * 2 + 1].sum;
}

void apply(int idx, int l, int r, int c, int d) {
  int len = r - l + 1;
  int sum_i = (l + r) * len / 2;
  tree[idx].sum += c * len + d * sum_i;
  tree[idx].add += c;
  tree[idx].addi += d;
}

void push(int idx, int l, int r) {
  if (tree[idx].add == 0 && tree[idx].addi == 0)
    return;
  int mid = (l + r) / 2;
  apply(idx * 2, l, mid, tree[idx].add, tree[idx].addi);
  apply(idx * 2 + 1, mid + 1, r, tree[idx].add, tree[idx].addi);
  tree[idx].add = tree[idx].addi = 0;
}

void update(int idx, int l, int r, int ql, int qr) {
  if (ql <= l && r <= qr) {
    apply(idx, l, r, 1 - ql, 1);
    return;
  }
  push(idx, l, r);
  int mid = (l + r) / 2;
  if (ql <= mid)
    update(idx * 2, l, mid, ql, qr);
  if (qr > mid)
    update(idx * 2 + 1, mid + 1, r, ql, qr);
  tree[idx].sum = tree[idx * 2].sum + tree[idx * 2 + 1].sum;
}

int query(int idx, int l, int r, int ql, int qr) {
  if (ql <= l && r <= qr)
    return tree[idx].sum;
  push(idx, l, r);
  int mid = (l + r) / 2;
  int res = 0;
  if (ql <= mid)
    res += query(idx * 2, l, mid, ql, qr);
  if (qr > mid)
    res += query(idx * 2 + 1, mid + 1, r, ql, qr);
  return res;
}

signed main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> q;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i)
    cin >> a[i];
  tree.resize(4 * n + 5);
  build(1, 1, n, a);
  while (q--) {
    int type, a, b;
    cin >> type >> a >> b;
    if (type == 1) {
      update(1, 1, n, a, b);
    } else {
      cout << query(1, 1, n, a, b) << '\n';
    }
  }
  return 0;
}