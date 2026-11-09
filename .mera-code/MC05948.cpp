#include <bits/stdc++.h>

using namespace std;

#define int long long

using LL = long long;
using VI = vector<int>;

const int kMaxN = 2e5 + 7;

int manacher_suffix_start(string s) {
  int n0 = s.size();
  string t = "#";
  for (char c : s) {
    t += c;
    t += '#';
  }
  int n = t.size();
  vector<int> d(n, 0);
  int l = 0, r = -1;
  for (int i = 0; i < n; i++) {
    int k = (i > r) ? 1 : min(d[l + r - i], r - i + 1);
    while (i - k >= 0 && i + k < n && t[i - k] == t[i + k]) {
      k++;
    }
    d[i] = k--;
    if (i + k > r) {
      l = i - k;
      r = i + k;
    }
  }
  int best = 0, start = n0 - 1;
  for (int i = 0; i < n; i++) {
    if (i + d[i] - 1 == n - 1) {
      int len = d[i] - 1;
      if (len > best) {
        best = len;
        start = (i - d[i] + 1) / 2;
      }
    }
  }
  return start;
}

signed main() {
  ios::sync_with_stdio(0), cin.tie(0);
  string s;
  while (cin >> s) {
    int st = manacher_suffix_start(s);
    string ans = s;
    for (int i = st - 1; i >= 0; i--) {
      ans += s[i];
    }
    cout << ans << '\n';
  }
  return 0;
}