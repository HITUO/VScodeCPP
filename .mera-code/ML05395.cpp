#include <bits/stdc++.h>

using namespace std;

#define int long long

const int kN = 2e9;

struct Node {
  int addv;
  int maxv;
};

struct Interval {
  int l, r, len;
};

bool cmp(const Interval &a, const Interval &b) { return a.len < b.len; }

int XC;
vector<Node> tree;

void update(int ql, int qr, int v, int idx = 1, int l = 1, int r = XC) {
  if (ql <= l && r <= qr) {
    tree[idx].addv += v;
    tree[idx].maxv += v;
    return;
  }
  int mid = (l + r) >> 1;
  int left = idx << 1, right = left | 1;
  if (tree[idx].addv) {
    tree[left].addv += tree[idx].addv;
    tree[left].maxv += tree[idx].addv;
    tree[right].addv += tree[idx].addv;
    tree[right].maxv += tree[idx].addv;
    tree[idx].addv = 0;
  }
  if (ql <= mid)
    update(ql, qr, v, left, l, mid);
  if (qr > mid)
    update(ql, qr, v, right, mid + 1, r);
  tree[idx].maxv = max(tree[left].maxv, tree[right].maxv);
}

signed main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n, m;
  cin >> n >> m;
  vector<Interval> in(n);
  map<int, int> mp;
  for (int i = 0; i < n; i++) {
    cin >> in[i].l >> in[i].r;
    in[i].len = in[i].r - in[i].l;
    mp[in[i].l] = 0;
    mp[in[i].r] = 0;
  }
  sort(in.begin(), in.end(), cmp);
  XC = 0;
  for (auto &p : mp) {
    p.second = ++XC;
  }
  tree.resize(4 * XC + 5);
  int ans = 2e9;
  int L = 0;
  for (int R = 0; R < n; R++) {
    int ql = mp[in[R].l];
    int qr = mp[in[R].r];
    update(ql, qr, 1);
    while (tree[1].maxv >= m) {
      ans = min(ans, in[R].len - in[L].len);
      ql = mp[in[L].l];
      qr = mp[in[L].r];
      update(ql, qr, -1);
      L++;
    }
  }
  if (ans == 2e9) {
    cout << -1 << '\n';
  } else {
    cout << ans << '\n';
  }
  return 0;
}