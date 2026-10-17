#include <bits/stdc++.h>

using namespace std;

#define int long long

using LL = long long;
using VI = vector<int>;

const int kMaxN = 3e4 + 7;

struct Impossible {};

struct V {
  int from, to, next, w;
} edge[kMaxN << 2];

int n, m, num_edge, tot;
int a[kMaxN], dis[kMaxN], head[kMaxN], cnt[kMaxN];
bool vis[kMaxN];
queue<int> q;

void add(int u, int v, int w) {
  edge[++num_edge] = {u, v, head[u], w};
  head[u] = num_edge;
}

int SPFA() {
  fill(dis, dis + kMaxN, 0x3f3f3f3f);
  dis[0] = 0;
  vis[0] = 1;
  q.push(0);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    vis[u] = 0;
    for (int i = head[u]; ~i; i = edge[i].next) {
      int v = edge[i].to, w = edge[i].w;
      if (dis[v] > dis[u] + w) {
        dis[v] = dis[u] + w;
        cnt[v] = cnt[u] + 1;
        if (cnt[v] > n) {
          return 0;
        }
        if (!vis[v]) {
          vis[v] = 1;
          q.push(v);
        }
      }
    }
  }
  return 1;
}

signed main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  try {
    fill(head, head + kMaxN, -1);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
      int opt, a, b, c;
      cin >> opt >> a >> b;
      if (opt == 3) {
        goto skip;
      }
      cin >> c;
    skip:
      switch (opt) {
      case 1:
        add(a, b, -c);
        break;
      case 2:
        add(b, a, c);
        break;
      case 3:
        add(a, b, 0);
        break;
      default:
        throw Impossible();
      }
    }
    for (int i = 1; i <= n; i++) {
      add(0, i, 0);
    }
    if (SPFA()) {
      cout << "Yes";
    } else {
      cout << "No";
    }
  } catch (Impossible) {
    cout << "Error!";
  }
  return 0;
}