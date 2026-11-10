#include <bits/stdc++.h>

using namespace std;

#define int long long

using LL = long long;
using VI = vector<int>;

const int kMaxN = 2e5 + 7;

char s[kMaxN], t[kMaxN];
int p[kMaxN], l[kMaxN], r[kMaxN], n, m, ans = 0;

void manacher() {
  m = 2 * n + 1;
  t[0] = '#';
  for (int i = 0; i < n; i++) {
    t[2 * i + 1] = s[i];
    t[2 * i + 2] = '#';
  }
  int maxn = 0, idx = 0;
  for (int i = 1; i < m; i++) {
    p[i] = (maxn > i) ? min(p[2 * idx - i], maxn - i) : 1;
    while (i - p[i] >= 0 && i + p[i] < m && t[i - p[i]] == t[i + p[i]]) {
      p[i]++;
    }
    if (i + p[i] > maxn) {
      maxn = i + p[i];
      idx = i;
    }
  }
}

signed main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> s;
  n = strlen(s);
  manacher();
  for (int i = 1; i < m; i++) {
    int ll = (i - p[i] + 2) / 2, rr = (i + p[i] - 2) / 2;
    if (ll <= rr) {
      l[rr] = max(l[rr], rr - ll + 1);
      r[ll] = max(r[ll], rr - ll + 1);
    }
  }
  for (int i = n - 2; i >= 0; i--) {
    l[i] = max(l[i], l[i + 1] - 2);
  }
  for (int i = 1; i < n; i++) {
    r[i] = max(r[i], r[i - 1] - 2);
  }
  for (int i = 0; i + 1 < n; i++) {
    if (l[i] >= 1 && r[i + 1] >= 1) {
      ans = max(ans, l[i] + r[i + 1]);
    }
  }
  cout << ans;
  return 0;
}