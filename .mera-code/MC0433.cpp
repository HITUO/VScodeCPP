#include <bits/stdc++.h>

using namespace std;

#define int long long

using LL = long long;
using VI = vector<int>;

const int kMaxN = 2e5 + 7, MOD = 998244353;

int n, ans, cnt;
string s;

signed main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> s;
  for (int i = 1; i <= (int)s.size(); i++) {
    if (s[i - 1] == '0') {
      (ans += cnt * (n - i + 1)) %= MOD;
    } else {
      (cnt += i) %= MOD;
    }
  }
  cout << ans;
  return 0;
}