#include <bits/stdc++.h>

using namespace std;

#define int long long

using LL = long long;
using VI = vector<int>;

const int kMaxN = 1e5 + 7;

struct V {
  int from, to, next, w;
} edge[kMaxN << 2];

int n, k, num_edge, ans;
int head[kMaxN], dp[kMaxN], sum[kMaxN];

void add(int u, int v, int w) {
  edge[++num_edge] = {u, v, head[u], w};
  head[u] = num_edge;
}

void dfs1(int u, int fa) {
  for (int i = head[u]; ~i; i = edge[i].next) {
    int v = edge[i].to, w = edge[i].w;
    if (v == fa) {
      continue;
    }
    dfs1(v, u);
    dp[u] += max(0LL, dp[v] + w - k);
  }
}

void dfs2(int u, int fa) {
  ans = max(ans, dp[u] + sum[u]);
  for (int i = head[u]; ~i; i = edge[i].next) {
    int v = edge[i].to, w = edge[i].w;
    if (v == fa) {
      continue;
    }
    sum[v] = sum[u] + dp[u] - max(0LL, dp[v] + w - k) + w;
    dfs2(v, u);
  }
}

signed main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  fill(head, head + kMaxN, -1);
  cin >> n >> k;
  for (int i = 1; i < n; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    add(x, y, z);
    add(y, x, z);
  }
  dfs1(1, 0);
  dfs2(1, 0);
  cout << ans;
  return 0;
}