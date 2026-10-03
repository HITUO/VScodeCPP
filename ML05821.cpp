#include <bits/stdc++.h>

using namespace std;

#define int long long

using LL = long long;
using VI = vector<int>;

const int kMaxN = 1e6 + 7, INF = 1e9;

struct V {
  int x, y, type, idx;
};

vector<V> nodes;
int ans[kMaxN];

struct SegTree {
  int n;
  VI mx;

  SegTree(int n) : n(n), mx(4 * n + 5, -INF) {}

  void update(int idx, int l, int r, int pos, int val) {
    if (l == r) {
      mx[idx] = max(mx[idx], val);
      return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid) {
      update(idx * 2, l, mid, pos, val);
    } else {
      update(idx * 2 + 1, mid + 1, r, pos, val);
    }
    mx[idx] = max(mx[idx * 2], mx[idx * 2 + 1]);
  }

  int query(int idx, int l, int r, int ql, int qr) {
    if (ql > r || qr < l) {
      return -INF;
    }
    if (ql <= l && r <= qr) {
      return mx[idx];
    }
    int mid = (l + r) / 2;
    return max(query(idx * 2, l, mid, ql, qr),
               query(idx * 2 + 1, mid + 1, r, ql, qr));
  }
};

void scan(int dir) {
  sort(nodes.begin(), nodes.end(), [dir](V &a, V &b) {
    if (a.x != b.x) {
      if (dir < 2) {
        return a.x < b.x;
      } else {
        return a.x > b.x;
      }
    }
    return a.type < b.type;
  });
  SegTree seg(kMaxN);
  for (auto &nd : nodes) {
    if (nd.type == 0) {
      int val;
      if (dir == 0) {
        val = nd.x + nd.y;
      } else if (dir == 1) {
        val = nd.x - nd.y;
      } else if (dir == 2) {
        val = -nd.x + nd.y;
      } else {
        val = -nd.x - nd.y;
      }
      seg.update(1, 1, kMaxN, nd.y, val);
    } else {
      int ql, qr;
      if (dir == 0 || dir == 2) {
        ql = 1;
        qr = nd.y;
      } else {
        ql = nd.y;
        qr = kMaxN;
      }
      int best = seg.query(1, 1, kMaxN, ql, qr);
      if (best != -INF) {
        int cur;
        if (dir == 0) {
          cur = (nd.x + nd.y) - best;
        } else if (dir == 1) {
          cur = (nd.x - nd.y) - best;
        } else if (dir == 2) {
          cur = (-nd.x + nd.y) - best;
        } else {
          cur = (-nd.x - nd.y) - best;
        }
        ans[nd.idx] = min(ans[nd.idx], cur);
      }
    }
  }
}

signed main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    nodes.push_back({x, y, 0, -1});
  }
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    nodes.push_back({x, y, 1, i});
    ans[i] = INF;
  }
  for (int d = 0; d < 4; d++) {
    scan(d);
  }
  int res = 0;
  for (int i = 0; i < m; i++) {
    res = max(res, ans[i]);
  }
  cout << res;
  return 0;
}