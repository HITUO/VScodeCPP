#include <bits/stdc++.h>

using namespace std;

#define int long long

using LL = long long;
using VI = vector<int>;

const int kMaxN = 2e5 + 7;

int T, n, d;

signed main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> T;
  while (T--) {
    cin >> n >> d;
    vector<pair<int, int>> xx;
    for (int i = 1; i <= n; i++) {
      int x, y;
      cin >> x >> y;
      xx.push_back({x, y});
    }
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        int x = xx[i].first - xx[j].first;
        int y = xx[i].second - xx[j].second;
        if (x * x + y * y <= d * d) {
          g[i].push_back(j);
          g[j].push_back(i);
        }
      }
    }
    VI vis(n + 1, -1);
    bool f = 1;
    for (int i = 1; i <= n; i++) {
      if (vis[i] != -1)
        continue;
      queue<int> q;
      q.push(i);
      vis[i] = 0;
      while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : g[u]) {
          if (vis[v] == -1) {
            vis[v] = vis[u] ^ 1;
            q.push(v);
          } else if (vis[u] == vis[v]) {
            f = 0;
            break;
          }
        }
        if (f == 0) {
          break;
        }
      }
      if (f == 0) {
        break;
      }
    }
    if (f == 0) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
  }
  return 0;
}