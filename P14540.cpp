#include <bits/stdc++.h>

using namespace std;

#define int long long

using LL = long long;
using VI = vector<int>;

const int kMaxN = 2e5 + 7;

struct V {
  int from, to, next, w;
} edge[kMaxN << 2];

struct node {
  int id, d;
  bool operator<(const node &b) const { return d > b.d; }
};

int n, m, num_edge;
int a[kMaxN], dis[kMaxN], head[kMaxN];
bool vis[kMaxN];

void add(int u, int v, int w) {
  edge[++num_edge] = {u, v, head[u], w};
  head[u] = num_edge;
}

void Dijkstra(int strart) {
  fill(dis, dis + n + 1, LLONG_MAX);
  fill(vis, vis + n + 1, 0);
  dis[strart] = 0;
  priority_queue<node> q;
  q.push({strart, 0});
  while (!q.empty()) {
    int u = q.top().id;
    q.pop();
    if (vis[u]) {
      continue;
    }
    vis[u] = 1;
    for (int i = head[u]; ~i; i = edge[i].next) {
      int v = edge[i].to, w = edge[i].w;
      if (dis[v] > dis[u] + w) {
        dis[v] = dis[u] + w;
        q.push({v, dis[v]});
      }
    }
  }
}

signed main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  fill(head, head + kMaxN, -1);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    add(0, i, a[i]);
  }
  for (int i = 1; i <= m; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    add(x, y, 2 * z);
    add(y, x, 2 * z);
  }
  Dijkstra(0);
  for (int i = 1; i <= n; i++) {
    cout << dis[i] << " ";
  }
  return 0;
}