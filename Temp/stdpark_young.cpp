#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
const ll INF = (ll)4e18;

int n;
vector<ll> w;
vector<vector<int>> adj;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  if (fopen("young.in", "r")) {
    freopen("young.in", "r", stdin);
    freopen("young.out", "w", stdout);
  }
  cin >> n;
  w.assign(n + 1, 0);
  for (int i = 1; i <= n; i++)
    cin >> w[i];
  adj.assign(n + 1, {});
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  // ---- 迭代 DFS：求 in/out、父节点、子树和 ----
  vector<int> par(n + 1, 0), in(n + 1), sz(n + 1), order;
  order.reserve(n);
  vector<int> stk;
  stk.reserve(n);
  stk.push_back(1);
  int timer = 0;
  while (!stk.empty()) {
    int v = stk.back();
    stk.pop_back();
    in[v] = ++timer;
    order.push_back(v);
    for (int to : adj[v]) {
      if (to == par[v])
        continue;
      par[to] = v;
      stk.push_back(to);
    }
  }
  vector<ll> s(n + 1);
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
  vector<int> out(n + 1);
  for (int v = 1; v <= n; v++)
    out[v] = in[v] + sz[v] - 1;
  ll T = s[1];

  // ---- 预处理（与二分答案无关的部分）----
  // subMin[v] = min{s_f : f 在 v 子树内(含 v)}；trueMin[v] = min{s_f : f 是 v
  // 的真后代}
  vector<ll> subMin(n + 1), trueMin(n + 1, INF);
  for (int v = 1; v <= n; v++)
    subMin[v] = s[v];
  for (int i = n - 1; i >= 0; i--) {
    int v = order[i], p = par[v];
    if (p) {
      subMin[p] = min(subMin[p], subMin[v]);
      trueMin[p] = min(trueMin[p], subMin[v]);
    }
  }
  // preMin[i] = min{s_f : out_f <= i}；sufMin[i] = min{s_f : in_f >= i}
  vector<ll> preMin(n + 2, INF), sufMin(n + 3, INF);
  for (int v = 2; v <= n; v++) {
    preMin[out[v]] = min(preMin[out[v]], s[v]);
    sufMin[in[v]] = min(sufMin[in[v]], s[v]);
  }
  for (int i = 1; i <= n; i++)
    preMin[i] = min(preMin[i], preMin[i - 1]);
  for (int i = n; i >= 1; i--)
    sufMin[i] = min(sufMin[i], sufMin[i + 1]);

  vector<ll> mx(n + 1),
      mn(n + 1); // mx[v]/mn[v]: 根到 v 路径上 s 的最大/最小值(含 v)

  // ---- check(X)：能否删两条边使至少两个连通块权值 >= X ----
  auto check = [&](ll X) -> bool {
    // 模式B(嵌套,e为f祖先)：块 {s_f, s_e-s_f, T-s_e}
    // B1: s_f>=X && s_e>=s_f+X     B2: s_f>=X && s_e<=T-X
    // 注意：e 必须是“非根节点对应的边”，根不能作为子树根，故 mx/mn 不含 s[1]
    bool b1 = false, b2 = false;
    mx[1] = -INF;
    mn[1] = INF;
    for (int v : order) {
      if (v == 1)
        continue;
      int p = par[v];
      if (s[v] >= X) {
        if (mx[p] >= s[v] + X)
          b1 = true;
        if (mn[p] <= T - X)
          b2 = true;
      }
      mx[v] = max(mx[p], s[v]);
      mn[v] = min(mn[p], s[v]);
    }
    if (b1 || b2)
      return true;

    // A1: 存在互不包含的两条边，子树和都 >= X
    ll maxInG = -1, minOutG = INF;
    for (int v = 2; v <= n; v++) {
      if (s[v] >= X) {
        if (in[v] > maxInG)
          maxInG = in[v];
        if (out[v] < minOutG)
          minOutG = out[v];
      }
    }
    if (maxInG >= 1) {
      for (int v = 2; v <= n; v++) {
        if (s[v] >= X && (maxInG > out[v] || minOutG < in[v]))
          return true;
      }
    }

    // A2: 存在互不包含(e,f)：s_e>=X 且 T-s_e-s_f>=X (s_f <= T-X-s_e)
    for (int v = 2; v <= n; v++) {
      if (s[v] >= X) {
        ll lim = T - X - s[v];
        if (sufMin[out[v] + 1] <= lim || preMin[in[v] - 1] <= lim)
          return true;
      }
    }

    // B3: 存在嵌套(e,f)：s_e<=T-X 且 s_e-s_f>=X
    for (int v = 2; v <= n; v++) {
      if (s[v] <= T - X && trueMin[v] <= s[v] - X)
        return true;
    }
    return false;
  };

  // ---- 二分答案（单调：X 可行则更小也可行）----
  ll lo = -500000000000000LL,
     hi = 500000000000000LL; // 每个块权值绝对值 <= sum|w| <= 5e14
  while (lo < hi) {
    ll mid = lo + (hi - lo + 1) / 2;
    if (check(mid))
      lo = mid;
    else
      hi = mid - 1;
  }
  cout << lo << "\n";
  return 0;
}
