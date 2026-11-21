#include <bits/stdc++.h>

using namespace std;

#define int long long

using LL = long long;
using VI = vector<int>;

const int kMaxN = 2e5 + 7, kMaxM = 1e3 + 7;

int n, q, r[kMaxN], c[kMaxN], tot = 0, ans = 0, s[kMaxM * kMaxM];
char t[kMaxN], g[kMaxM][kMaxM];
bool vis[kMaxM][kMaxM], vv[kMaxM][kMaxM];
const pair<int, int> d[] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int find(int x) { return s[x] == x ? x : s[x] = find(s[x]); }

void dfs(int x, int y) {
  if (x < 1 || x > n || y < 1 || y > n) {
    return;
  }
  if (vv[x][y] == 1) {
    if (g[x][y] == 'L') {
      dfs(x - 1, y);
    } else if (g[x][y] == 'R') {
      dfs(x + 1, y);
    } else if (g[x][y] == 'U') {
      dfs(x, y - 1);
    } else if (g[x][y] == 'D') {
      dfs(x, y + 1);
    }
  } else {
    for (int i = 0; i < 4; i++) {
      int tx = x + d[i].first, ty = y + d[i].second;
      return dfs(tx, ty);
    }
  }
}

signed main() {
  ios::sync_with_stdio(0), cin.tie(0);
  memset(vv, 0, sizeof(vv));
  cin >> n >> q;
  for (int i = 1; i <= q; i++) {
    cin >> r[i] >> c[i] >> t[i];
    g[r[i]][c[i]] = t[i];
    vv[r[i]][c[i]] = 1;
    for (int i = 1; i <= n * n + 7; i++) {
      s[i] = i;
    }
    memset(vis, 0, sizeof(vis));
    for (int x = 1; x <= n; x++) {
      for (int y = 1; y <= n; y++) {
        dfs(x, y);
      }
    }
    cout << ans << "\n";
  }
  return 0;
}