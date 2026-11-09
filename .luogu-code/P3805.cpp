#include <bits/stdc++.h>

using namespace std;

#define int long long

using LL = long long;
using VI = vector<int>;

const int kMaxN = 2e5 + 7;

string s;

string manacher(string s) {
  if (s.empty()) {
    return "";
  }
  string t = "#";
  for (char c : s) {
    t += c;
    t += '#';
  }
  int n = t.size();
  vector<int> d(n, 0);
  int l = 0, r = -1, center = 0;
  for (int i = 0; i < n; i++) {
    int k = (i > r) ? 1 : min(d[l + r - i], r - i + 1);
    while (i - k >= 0 && i + k < n && t[i - k] == t[i + k])
      k++;
    d[i] = k--;
    if (i + k > r) {
      l = i - k;
      r = i + k;
    }
    if (d[i] > d[center]) {
      center = i;
    }
  }
  return s.substr((center - d[center] + 1) / 2, d[center] - 1);
}

signed main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> s;
  cout << manacher(s).size();
  return 0;
}