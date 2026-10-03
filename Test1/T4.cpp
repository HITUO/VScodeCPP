#include <bits/stdc++.h>

using namespace std;

#define int long long

using LL = long long;
using VI = vector<int>;

const int kMaxN = 2e5 + 7;

int n, ans = INT_MAX, tans = 0;
VI vis;
vector<VI> g;

void dfs(int u, int fa) {
  if (vis[u] == 0) {
    tans++;
    vis[u] = 2;
    for (auto v : g[u]) {
      vis[v] = 1;
    }
  }
  for (auto v : g[u]) {
    if (v == fa) {
      continue;
    }
    if (vis[u] == 2 || vis[u] == 1) {
      dfs(v, u);
    }
  }
}

signed main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  vis.resize(n);
  g.resize(n);
  for (int i = 0; i < n; i++) {
    int id, k;
    cin >> id >> k;
    if (k == 0) {
      continue;
    }
    for (int j = 1; j <= k; j++) {
      int x;
      cin >> x;
      g[id].push_back(x);
      g[x].push_back(id);
    }
  }
  for (int i = 0; i < n; i++) {
    fill(vis.begin(), vis.end(), 0);
    vis[i] = 2;
    tans = 1;
    for (auto v : g[i]) {
      vis[v] = 1;
    }
    dfs(i, -1);
    ans = min(ans, tans);
  }
  cout << ans;
  return 0;
}

/*
5
0 2 1 2
1 2 3 4
2 0
3 0
4 0
*/