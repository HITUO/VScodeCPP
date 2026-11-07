#include <bits/stdc++.h>

using namespace std;

#define int long long

using LL = long long;
using VI = vector<int>;

const int kMaxN = 2e5 + 7;

// inline int read() {
//   int x = 0, f = 1;
//   char c = getchar();
//   while (c < '0' || c > '9') {
//     if (c == '-') {
//       f = -1;
//     }
//     c = getchar();
//   }
//   while (c >= '0' && c <= '9') {
//     x = x * 10 + (c - '0');
//     c = getchar();
//   }
//   return x * f;
// }

int T, a[kMaxN], sum[kMaxN];

signed main() {
  freopen("square.in", "r", stdin);
  freopen("square.out", "w", stdout);
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> T;
  for (int cse = 1; cse <= T; cse++) {
    int n, ans = 0;
    cin >> n;
    memset(sum, 0, sizeof(sum));
    // VI sum(n + 1, 0);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      sum[i] = sum[i - 1] + a[i];
    }
    for (int i = 1; i <= n; i++) {
      for (int j = i; j <= n; j++) {
        double x = sqrt(sum[j] - sum[i - 1]);
        if (x == (int)x) {
          ans++;
        }
      }
    }
    cout << "Case #" << cse << ": " << ans << "\n";
  }
  return 0;
}