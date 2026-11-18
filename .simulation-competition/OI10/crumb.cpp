#include <bits/stdc++.h>

using namespace std;

#define int long long

using LL = long long;
using VI = vector<int>;

const int kMaxN = 2e5 + 7;

int T, n, k;

signed main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> T;
  while (T--) {
    cin >> n >> k;
    if (n * 3 < k) {
      cout << "-1\n";
      continue;
    }
    if (n > k) {
      cout << n - k << "\n";
      continue;
    }
    if (k == 3 * n - 1) {
      cout << "-1\n";
      continue;
    }
    int duo = k - n;
    if (duo % 2 == 0) {
      cout << "0\n";
      continue;
    }
    cout << 1 << "\n";
  }
  return 0;
}