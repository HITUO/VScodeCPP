#include <bits/stdc++.h>

using namespace std;

#define int long long

using LL = long long;
using VI = vector<int>;

const int kMaxN = 2e5 + 7;

int T, ans;
string s;

signed main() {
  freopen("replace.in", "r", stdin);
  freopen("replace.out", "w", stdout);
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> T;
  while (T--) {
    ans = 1;
    bool f1 = 0, f2 = 0;
    int pos = '#', cnt = 1;
    VI k;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
      if (pos == '#') {
        pos = s[0];
        cnt = 1;
        continue;
      }
      if (pos != s[i]) {
        k.push_back(cnt);
        pos = s[i];
        cnt = 1;
      } else {
        cnt++;
      }
    }
    k.push_back(cnt);
    // for (auto i : k) {
    //   cout << i << " ";
    // }
    for (int i = 0; i < k.size(); i++) {
      if (k[i] >= 3) {
        f2 = 1;
        break;
      }
    }
    for (int i = 1; i < k.size() - 1; i++) {
      if (k[i] == 1 && !f1) {
        f1 = 1;
        break;
      }
    }
    cout << ans + f1 + f2 << "\n";
  }
  return 0;
}