#include <bits/stdc++.h>

using namespace std;

#define int long long

using LL = long long;
using VI = vector<int>;

const int kMaxN = 2e5 + 7;

signed main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n, ans = 0;
  cin >> n;
  string s;
  cin >> s;
  for (int i = 0; i < (int)s.size(); i++) {
    bool f = 0;
    for (int j = i; j < (int)s.size(); j++) {
      if (f || s[j] == '1') {
        ans++;
        f = 1;
      }
    }
  }
  cout << ans;
  return 0;
}