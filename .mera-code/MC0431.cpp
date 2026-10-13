#include <bits/stdc++.h>

using namespace std;

#define int long long

using LL = long long;
using VI = vector<int>;

const int kMaxN = 2e5 + 7;

string s;
int n;

signed main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> s >> n;
  while (n--) {
    string t;
    cin >> t;
    int i = 0, j = 0;
    while (i < (int)s.size() && j < (int)t.size()) {
      if (s[i] == t[j]) {
        i++;
        j++;
      } else {
        i++;
      }
    }
    if (j == (int)t.size()) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}