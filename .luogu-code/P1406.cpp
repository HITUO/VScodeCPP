
#include <bits/stdc++.h>

using namespace std;

using LL = long long;

const int kMaxN = 20;

int n, a[kMaxN][kMaxN], b[kMaxN][kMaxN], sum = 0, s;
vector<int> v;
bool vis[kMaxN * kMaxN];

bool dfs(int x, int y) {
  if (x > n) {
    return 1;
  }
  int nx = x, ny = y + 1;
  if (ny > n) {
    nx++;
    ny = 1;
  }
  for (int i = 0; i < v.size(); i++) {
    if (vis[i]) {
      continue;
    }
    b[x][y] = v[i];
    vis[i] = 1;
    bool ok = 1;
    if (y == n) {
      int ss = 0;
      for (int j = 1; j <= n; j++) {
        ss += b[x][j];
      }
      if (ss != s) {
        ok = 0;
      }
    }
    if (x == n) {
      int ss = 0;
      for (int j = 1; j <= n; j++) {
        ss += b[j][y];
      }
      if (ss != s) {
        ok = 0;
      }
    }
    if (x == n && y == n) {
      int ss = 0;
      for (int j = 1; j <= n; j++) {
        ss += b[j][j];
      }
      if (ss != s) {
        ok = 0;
      }
    }
    if (x == n && y == 1) {
      int ss = 0;
      for (int j = 1; j <= n; j++) {
        ss += b[j][n - j + 1];
      }
      if (ss != s) {
        ok = 0;
      }
    }
    if (ok && dfs(nx, ny)) {
      return 1;
    }
    vis[i] = 0;
  }
  return 0;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> a[i][j];
      sum += a[i][j];
      v.push_back(a[i][j]);
    }
  }
  if (sum % n != 0) {
    throw "error1";
    return 0;
  }
  s = sum / n;
  cout << s << "\n";
  sort(v.begin(), v.end());
  if (dfs(1, 1)) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        cout << b[i][j] << " ";
      }
      cout << "\n";
    }
  } else {
    throw "error2";
  }
  return 0;
}