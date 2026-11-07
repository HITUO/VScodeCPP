#include <bits/stdc++.h>

using namespace std;

#define int long long

using LL = long long;
using VI = vector<int>;

const int kMaxN = 2e5 + 7;

VI a;
int dp[kMaxN], ans;

VI zs(VI &kk) {
  VI dp, kkk;
  for (int x : kk) {
    auto it = lower_bound(dp.begin(), dp.end(), x);
    if (it == dp.end()) {
      dp.push_back(x);
    } else {
      kkk.push_back(x);
      *it = x;
    }
  }
  return kkk;
}

signed main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int x;
  while (cin >> x) {
    a.push_back(x);
  }
  VI b = a;
  reverse(b.begin(), b.end());
  VI t = zs(b);
  cout << a.size() - t.size() << "\n";
  while (!t.empty()) {
    t = zs(t);
    // for (auto i : t)
    //   cout << i << " ";
    ans++;
  }
  cout << ans + 1;
  return 0;
}