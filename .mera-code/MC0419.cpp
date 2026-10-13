#include <bits/stdc++.h>

using namespace std;

#define int long long

using LL = long long;
using VI = vector<int>;

const int kMaxN = 2e5 + 7;

signed main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  string s;
  set<string> ss;
  cin >> s;
  s = "#" + s;
  for (int i = 1; i <= (int)s.size(); i++) {
    for (int len = 1; len <= (int)s.size() - i; len++) {
      string t = "";
      for (int l = i; l <= i + len - 1; l++) {
        t += s[l];
      }
      // cout << t << "\n";
      ss.insert(t);
    }
  }
  cout << ss.size();
  return 0;
}