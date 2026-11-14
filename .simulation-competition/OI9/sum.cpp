#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ss(x, y) sum[y] - sum[x - 1]

using LL = long long;
using VI = vector<int>;

const int kMaxN = 5e5 + 7;

int n, m, ans = 0;
map<int, vector<pair<int, int>>> mp;

signed main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m;
  vector<VI> a(n + 1, VI(m + 1)), vis(n + 1, VI(m + 1, 0));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      mp[a[i][j]].push_back({i, j});
    }
  }
  for (auto ii : mp) {
    auto arr = ii.second;
    VI x, y;
    for (auto i : arr) {
      x.push_back(i.first);
      y.push_back(i.second);
    }
    sort(x.begin(), x.end());
    VI sum(x.size(), 0);
    sum[0] = x[0];
    for (int i = 1; i < x.size(); i++) {
      sum[i] = sum[i - 1] + x[i];
    }
    for (int i = 1; i < x.size(); i++) {
      int q = i * x[i] - sum[i - 1], h = 0;
      ans += q + h;
      // ans += i * x[i] - (sum[i - 1]) + (sum[x.size() - 1] - sum[i]) -
      //        (x.size() - 1 - i) * x[i];
    }
    sort(y.begin(), y.end());
    sum.clear();
    sum.resize(y.size(), 0);
    sum[0] = y[0];
    for (int i = 1; i < y.size(); i++) {
      sum[i] = sum[i - 1] + y[i];
    }
    for (int i = 1; i < y.size(); i++) {
      int q = i * y[i] - sum[i - 1], h = 0;
      ans += q + h;
      // ans += i * y[i] - (sum[i - 1]) + (sum[y.size() - 1] - sum[i]) -
      //        (y.size() - 1 - i) * y[i];
    }
  }
  cout << ans;
  return 0;
}