#include <bits/stdc++.h>

using namespace std;

#define int long long

using LL = long long;
using VI = vector<int>;

const int kMaxN = 1e6 + 7;

int n, a[kMaxN], c2, c5, t = 1;

signed main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    while (a[i] % 2 == 0) {
      c2++;
      a[i] /= 2;
    }
    while (a[i] % 5 == 0) {
      c5++;
      a[i] /= 5;
    }
    (t *= (a[i] % 10)) %= 10;
  }
  if (c2 == c5) {
    cout << t % 10;
    return 0;
  }
  for (int i = 1; i <= (c2 > c5 ? c2 - c5 : c5 - c2); i++) {
    (t *= (c2 > c5 ? 2 : 5)) %= 10;
  }
  cout << t % 10;
  return 0;
}