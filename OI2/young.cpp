#include <bits/stdc++.h>

using namespace std;

#define int long long

using LL = long long;
using VI = vector<int>;

const int kMaxN = 2e5 + 7, INF = 4e18;

int n;
VI w;
vector<VI> adj;

signed main() {
  ios::sync_with_stdio(0), cin.tie(0);
  freopen("young.in", "r", stdin);
  freopen("young.out", "w", stdout);
  cin >> n;
  w.assign(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    cin >> w[i];
  }
  adj.assign(n + 1, {});
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  VI par(n + 1, 0), in(n + 1), sz(n + 1), order;
  order.reserve(n);
  VI stk;
  stk.reserve(n);
  stk.push_back(1);
  int timer = 0;
  while (!stk.empty()) {
    int v = stk.back();
    stk.pop_back();
    in[v] = ++timer;
    order.push_back(v);
    for (int to : adj[v]) {
      if (to == par[v]) {
        continue;
      }
      par[to] = v;
      stk.push_back(to);
    }
  }
  VI s(n + 1);
  for (int v = 1; v <= n; v++) {
    s[v] = w[v];
    sz[v] = 1;
  }
  for (int i = n - 1; i >= 0; i--) {
    int v = order[i];
    if (par[v]) {
      s[par[v]] += s[v];
      sz[par[v]] += sz[v];
    }
  }
  VI out(n + 1);
  for (int v = 1; v <= n; v++) {
    out[v] = in[v] + sz[v] - 1;
  }
  int T = s[1];
  VI sub_min(n + 1), true_min(n + 1, INF);
  for (int v = 1; v <= n; v++) {
    sub_min[v] = s[v];
  }
  for (int i = n - 1; i >= 0; i--) {
    int v = order[i], p = par[v];
    if (p) {
      sub_min[p] = min(sub_min[p], sub_min[v]);
      true_min[p] = min(true_min[p], sub_min[v]);
    }
  }
  VI pre_min(n + 2, INF), suf_min(n + 3, INF);
  for (int v = 2; v <= n; v++) {
    pre_min[out[v]] = min(pre_min[out[v]], s[v]);
    suf_min[in[v]] = min(suf_min[in[v]], s[v]);
  }
  for (int i = 1; i <= n; i++) {
    pre_min[i] = min(pre_min[i], pre_min[i - 1]);
  }
  for (int i = n; i >= 1; i--) {
    suf_min[i] = min(suf_min[i], suf_min[i + 1]);
  }
  VI mx(n + 1), mn(n + 1);
  auto check = [&](int x) -> bool {
    bool b1 = 0, b2 = 0;
    mx[1] = -INF;
    mn[1] = INF;
    for (int v : order) {
      if (v == 1) {
        continue;
      }
      int p = par[v];
      if (s[v] >= x) {
        if (mx[p] >= s[v] + x) {
          b1 = 1;
        }
        if (mn[p] <= T - x) {
          b2 = 1;
        }
      }
      mx[v] = max(mx[p], s[v]);
      mn[v] = min(mn[p], s[v]);
    }
    if (b1 || b2) {
      return 1;
    }
    int max_in_g = -1, min_out_g = INF;
    for (int v = 2; v <= n; v++)
      if (s[v] >= x) {
        if (in[v] > max_in_g) {
          max_in_g = in[v];
        }
        if (out[v] < min_out_g) {
          min_out_g = out[v];
        }
      }
    if (max_in_g >= 1) {
      for (int v = 2; v <= n; v++) {
        if (s[v] >= x && (max_in_g > out[v] || min_out_g < in[v])) {
          return 1;
        }
      }
    }
    for (int v = 2; v <= n; v++) {
      if (s[v] > x) {
        int lim = T - x - s[v];
        if (suf_min[out[v] + 1] <= lim || pre_min[in[v] - 1] <= lim) {
          return 1;
        }
      }
    }
    for (int v = 2; v <= n; v++) {
      if (s[v] <= T - x && true_min[v] <= s[v] - x) {
        return 1;
      }
    }
    return 0;
  };
  int l = -500000000000000, r = 500000000000000;
  while (l < r) {
    int mid = l + (r - l + 1) / 2;
    if (check(mid)) {
      l = mid;
    } else {
      r = mid - 1;
    }
  }
  cout << r;
  return 0;
}