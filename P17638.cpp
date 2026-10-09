#include <bits/stdc++.h>

using namespace std;

using LL = long long;

const int kMaxN = 1e5 + 5, kPrime[4] = {2, 3, 5, 7};

struct Node {
  LL mx[4];
  LL lazy[4];
  LL ans;
};

Node seg[4 * kMaxN];
int n, q;

void apply(int idx, int p, LL v) {
  seg[idx].mx[p] += v;
  seg[idx].lazy[p] += v;
  seg[idx].ans = max(seg[idx].ans, seg[idx].mx[p]);
}

void pushdown(int idx) {
  for (int p = 0; p < 4; ++p) {
    if (seg[idx].lazy[p] == 0) {
      continue;
    }
    LL v = seg[idx].lazy[p];
    apply(idx * 2, p, v);
    apply(idx * 2 + 1, p, v);
    seg[idx].lazy[p] = 0;
  }
}

void pushup(int idx) {
  for (int p = 0; p < 4; ++p) {
    seg[idx].mx[p] = max(seg[idx * 2].mx[p], seg[idx * 2 + 1].mx[p]);
  }
  seg[idx].ans = 0;
  for (int p = 0; p < 4; ++p) {
    seg[idx].ans = max(seg[idx].ans, seg[idx].mx[p]);
  }
}

void add(int idx, int l, int r, int ql, int qr, int p, LL v) {
  if (ql <= l && r <= qr) {
    apply(idx, p, v);
    return;
  }
  pushdown(idx);
  int mid = (l + r) / 2;
  if (ql <= mid) {
    add(idx * 2, l, mid, ql, qr, p, v);
  }
  if (qr > mid) {
    add(idx * 2 + 1, mid + 1, r, ql, qr, p, v);
  }
  pushup(idx);
}

LL query(int idx, int l, int r, int ql, int qr) {
  if (ql <= l && r <= qr)
    return seg[idx].ans;
  pushdown(idx);
  int mid = (l + r) / 2;
  LL ret = 0;
  if (ql <= mid) {
    ret = max(ret, query(idx * 2, l, mid, ql, qr));
  }
  if (qr > mid) {
    ret = max(ret, query(idx * 2 + 1, mid + 1, r, ql, qr));
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr);
  cin >> n >> q;
  while (q--) {
    string op;
    cin >> op;
    if (op == "MULTIPLY") {
      int l, r, x;
      cin >> l >> r >> x;
      int copy = x;
      for (int p = 0; p < 4; ++p) {
        while (copy % kPrime[p] == 0) {
          add(1, 1, n, l, r, p, 1);
          copy /= kPrime[p];
        }
      }
    } else {
      int l, r;
      cin >> l >> r;
      cout << "ANSWER " << query(1, 1, n, l, r) << '\n';
    }
  }
  return 0;
}