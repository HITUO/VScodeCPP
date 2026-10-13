#include <bits/stdc++.h>

using namespace std;

#define int long long

using LL = long long;
using VI = vector<int>;

const int kMaxN = 2e5 + 7;

int n;

signed main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  VI a(n);
  vector<pair<int, int>> c;
  for (auto &i : a)
    cin >> i;
  sort(a.begin(), a.end());
  c.push_back({a[0], 1});
  for (int i = 1; i < (int)a.size(); i++) {
    if (a[i] == a[i - 1]) {
      c[(int)c.size() - 1].second++;
    } else {
      c.push_back({a[i], 1});
    }
  }
  int maxn = -LLONG_MAX;
  VI ans;
  for (auto [p, q] : c) {
    maxn = max(maxn, q);
  }
  for (auto [p, q] : c) {
    // cout << "p = " << p << "   q = " << q << "\n";
    if (q == maxn) {
      ans.push_back(p);
    }
  }
  // cout << "maxn = " << maxn << "\n";
  for (auto i : ans)
    cout << i << "\n";
  return 0;
}