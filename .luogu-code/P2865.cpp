#include <bits/stdc++.h>

using namespace std;

#define int long long

using LL = long long;
using VI = vector<int>;

const int kMaxN = 2e5 + 7;

struct Edge {
  int to, nxt, val;
} e[kMaxN];

int h[kMaxN], cnt, dis[3][kMaxN], n, m;

void add(int from, int to, int value) {
  e[++cnt] = {to, h[from], value};
  h[from] = cnt;
}

struct node {
  int pos, dis;
  friend bool operator<(node a, node b) { return a.dis > b.dis; }
} tmp;

priority_queue<node> q;

void dijkstra_2() {
  for (int i = 1; i <= n; i++) {
    dis[0][i] = dis[1][i] = INT_MAX;
  }
  dis[0][1] = 0;
  q.push(tmp = {1, 0});
  while (!q.empty()) {
    tmp = q.top();
    q.pop();
    int u = tmp.pos, d = tmp.dis;
    if (d > dis[1][u]) {
      continue;
    }
    for (int i = h[u]; i; i = e[i].nxt) {
      int v = e[i].to, w = e[i].val;
      if (dis[0][v] > d + w) {
        dis[1][v] = dis[0][v];
        tmp = {v, dis[0][v] = d + w};
        q.push(tmp);
      }
      if (dis[1][v] > d + w && dis[0][v] < d + w) {
        tmp = {v, dis[1][v] = d + w};
        q.push(tmp);
      }
    }
  }
}

signed main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    add(a, b, c);
    add(b, a, c);
  }
  dijkstra_2();
  cout << dis[1][n];
  return 0;
}