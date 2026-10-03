#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    string s;
    int lc = 0, rc = 0, ans = 0;
    cin >> s;
    for (int i = 0; i < (int)s.size(); i++) {
      if (s[i] == '(') {
        if (rc > 0) {
          ans += rc;
          rc--;
        } else
          lc++;
      } else {
        if (lc > 0)
          lc--;
        else
          rc++;
      }
    }
    cout << ans << "\n";
  }
  return 0;
}