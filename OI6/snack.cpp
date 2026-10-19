#include <bits/stdc++.h>

using namespace std;

#define int long long

using LL = long long;
using VI = vector<int>;

const int kMaxN = 2e5 + 7;

int n, minn = LLONG_MAX, ll[kMaxN * 2], vis[kMaxN * 2];
VI a[kMaxN * 2], ans;
queue<int> q;

signed main() {
  ios::sync_with_stdio(0), cin.tie(0);
  freopen("snack.in", "r", stdin);
  freopen("snack.out", "w", stdout);
  cin >> n;
  fill(vis, vis + kMaxN, 0);
  for (int i = 1; i <= n; i++) {
    int len;
    cin >> len;
    minn = min(minn, len);
    for (int j = 1; j <= len; j++) {
      int x;
      cin >> x;
      // i love x ( + n)
      a[x + n].push_back(i);
      a[i].push_back(x + n);
      ll[x + n]++;
      ll[i]++;
    }
  }
  if (minn > 1) {
    cout << "-1";
    return 0;
  }
  for (int i = n + 1; i <= n * 2; i++) {
    if (ll[i] == 1) {
      q.push(i);
    }
  }
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    vis[u] = 1;
    for (auto v : a[u]) {
      if (vis[v] == 1) {
        continue;
      }
      ans.push_back(v);
      vis[v] = 1;
      for (auto vv : a[v]) {
        if (vis[vv] == 1 || vv == u) {
          continue;
        }
        ll[vv]--;
        if (ll[vv] == 1) {
          q.push(vv);
        }
      }
    }
  }
  if (ans.size() != n) {
    cout << "-1";
    return 0;
  }
  reverse(ans.begin(), ans.end());
  for (int i : ans) {
    cout << i << " ";
  }
  return 0;
}