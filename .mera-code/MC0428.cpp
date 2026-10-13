#include <bits/stdc++.h>

using namespace std;

#define int long long
#define f(aaa) s[i] == aaa

using LL = long long;
using VI = vector<int>;

const int kMaxN = 2e5 + 7;

signed main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  string s;
  int ans = 0;
  cin >> s;
  for (int i = 0; i < (int)s.size(); i++) {
    if (f('a') || f('e') || f('i') || f('o') || f('u')) {
      ans++;
    }
  }
  cout << ans;
  return 0;
}