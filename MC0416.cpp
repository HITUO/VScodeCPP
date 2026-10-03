#include <bits/stdc++.h>
#include <climits>

using namespace std;

#define int long long

using LL = long long;
using VI = vector<int>;

const int kMaxN = 1e4 + 7;

int n, a[kMaxN], ans;

signed main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    int minn = LLONG_MAX;
    for (int j = i; j <= n; j++) {
      minn = min(minn, a[j]);
      ans += minn;
    }
  }
  cout << ans;
  return 0;
}