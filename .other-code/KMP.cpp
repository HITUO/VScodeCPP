#include <bits/stdc++.h>

using namespace std;

#define int long long

using LL = long long;
using VI = vector<int>;

const int kMaxN = 2e5 + 7;

string s, p;
int nxt[kMaxN];
VI ans;

signed main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> s >> p;
  int j = 0;
  for (int i = 0; i < s.size(); i++) {
    while (j != 0 && p[j] != p[i]) {
      j = nxt[j];
    }
    if (p[j] == p[i]) {
      j++;
    }
    nxt[i] = j;
  }
  j = 0;
  for (int i = 0; i < s.size(); i++) {
    while (j != 0 && p[j] != s[i]) {
      j = nxt[j];
    }
    if (p[j] == s[i]) {
      j++;
    }
    if (j == p.size()) {
      ans.push_back(i - p.size() + 1);
    }
  }
  return 0;
}