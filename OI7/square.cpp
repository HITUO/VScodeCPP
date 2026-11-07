#include <bits/stdc++.h>

using namespace std;

#define int long long

using LL = long long;
using VI = vector<int>;

const int kMaxN = 2e5 + 7;

int T, n, a[kMaxN], sum[kMaxN], ans;

signed main() {
  // freopen("square.in", "r", stdin);
  // freopen("square.out", "w", stdout);
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> T;
  for (int cse = 1; cse <= T; cse++) {
    ans = 0;
    cin >> n;
    fill(sum, sum + n + 2, 0);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      sum[i] = sum[i - 1] + a[i];
    }
    for (int i = 1; i <= n; i++) {
      for (int j = i; j <= n; j++) {
        double x = sqrt(sum[j] - sum[i - 1] * 1.0);
        if (x == (int)x) {
          ans++;
        }
      }
    }
    cout << "Case #" << cse << ": " << ans << "\n";
  }
  return 0;
}