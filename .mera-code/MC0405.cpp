#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using VI = vector<int>;

const int kMaxN = 1e6 + 7;

LL T, n, a[kMaxN], ans = 0;

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> T;
  while (T--) {
    ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      if (i > 1 && a[i] > 0) {
        ans += a[i];
      }
    }
    cout << ans << "\n";
  }
  return 0;
}