#include <bits/stdc++.h>

using namespace std;

#define int long long

using LL = long long;
using VI = vector<int>;

const int kMaxN = 2e5 + 7, kMaxM = 4e5 + 5, kN = 9e18 + 7;

int n, m, qq, head[kMaxN], edge_cnt, dis[kMaxN], vis[kMaxN], s, k;

struct edge {
  int v, nxt, w;
} edge[kMaxM << 1];

void add(int u, int v, int w) {
  edge[++edge_cnt] = {v, head[u], w};
  head[u] = edge_cnt;
}

priority_queue<pair<int, int>> q;

signed main() {
  freopen("maze.in", "r", stdin);
  freopen("maze.out", "w", stdout);
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  fill(head, head + kMaxN, -1);
  cin >> n >> m >> qq;
  for (int i = 1, x; i <= n; i++) {
    cin >> x;
    if (x != 0) {
      dis[i] = kN, q.push({kN, i});
    }
  }
  for (int i = 1; i <= m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    add(u, v, w);
    add(v, u, w);
  }
  while (!q.empty()) {
    int u = q.top().second;
    q.pop();
    if (vis[u] == 1) {
      continue;
    }
    vis[u] = 1;
    for (int i = head[u]; ~i; i = edge[i].nxt) {
      int v = edge[i].v, w = edge[i].w;
      if (dis[v] < dis[u] + w) {
        dis[v] = min(dis[u], dis[v] + w);
        q.push({dis[v], v});
      }
    }
  }
  while (qq--) {
    cin >> s >> k;
    if (dis[s] < k) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
    }
  }
  return 0;
}