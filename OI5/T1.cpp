#include <bits/stdc++.h>

using namespace std;

#define int long long

using LL = long long;
using VI = vector<int>;

const int kMaxN = 1e6 + 7;

string s1, s2, s3;
int n, a[kMaxN];
LL dp0[kMaxN], dp1[kMaxN];

signed main() {
  // freopen("column.in", "r", stdin);
  // freopen("column.out", "w", stdout);
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> s1 >> s2 >> s3;
  n = s1.size();
  for (int i = 0; i < n; i++) {
    a[i] = s1[i] - '0' + s2[i] - '0';
  }
  for (int i = n - 1; i >= 0; i--) {
    int C = s3[i] - '0';
    if (a[i] % 10 == C) {
      if (a[i] < 10) {
        dp0[i] += 1;
        dp0[i] += dp0[i + 1];
      } else {
        dp1[i] += 1;
        dp1[i] += dp0[i + 1];
      }
    }
    if ((a[i] + 1) % 10 == C) {
      if (a[i] + 1 < 10) {
        dp0[i] += dp1[i + 1];
      } else {
        dp1[i] += dp1[i + 1];
      }
    }
  }
  LL ans = 0;
  for (int i = 0; i < n; i++) {
    ans += dp0[i];
  }
  cout << ans;
  return 0;
}