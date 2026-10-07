#include <bits/stdc++.h>

using namespace std;

#define int long long

using LL = long long;
using VI = vector<int>;

const int kMaxN = 1e5 + 7;

int n, k, p, a[kMaxN], sum, minn = -1, ans = 1e18;
set<int> ss;
map<int, int> m;

signed main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> k >> p;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    (sum += a[i]) %= p;
  }
  for (int i = 1; i <= n; i++) {
    if (~i) {
      if (sum - minn >= k) {
        ans = min(ans, sum - minn);
      }
      int num = *ss.lower_bound(sum - k + p);
      if (sum + num + p >= k) {
        if (num > sum) {
          ans = min(ans, sum - num + p);
        }
      }
    }
  }
  if (sum >= k) {
    ans = min(ans, sum);
  }
  if (minn == -1) {
    minn = sum;
  } else {
    minn = min(minn, sum);
  }
  ss.insert(sum);
  minn = min(minn, sum);
  cout << ans;
  return 0;
}