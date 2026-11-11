#include <bits/stdc++.h>

using namespace std;

#define int long long

using LL = long long;
using VI = vector<int>;

const int kMaxN = 1e6 + 7;

signed main() {
  // freopen("sequence.in", "r", stdin);
  // freopen("sequence.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  vector<long long> a(n + 1), b(n + 1);
  for (int i = 1; i <= n; ++i)
    cin >> a[i];
  for (int i = 1; i <= n; ++i)
    cin >> b[i];

  deque<pair<int, long long>> dq;
  long long active = 0, ans = 0;
  for (int i = 1; i <= n; ++i) {
    long long d = b[i] - a[i];
    if (d < 0) {
      cout << -1 << '\n';
      return 0;
    }
    while (!dq.empty() && dq.front().first <= i - k) {
      active -= dq.front().second;
      dq.pop_front();
    }
    if (active > d) {
      long long rem = active - d;
      while (rem > 0) {
        auto &f = dq.front();
        long long take = min(rem, f.second);
        f.second -= take;
        active -= take;
        rem -= take;
        if (f.second == 0)
          dq.pop_front();
      }
    } else if (active < d) {
      long long need = d - active;
      ans += need;
      active = d;
      if (!dq.empty() && dq.back().first == i)
        dq.back().second += need;
      else
        dq.push_back({i, need});
    }
  }

  cout << ans << '\n';
  return 0;
}