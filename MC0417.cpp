#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

#define int long long

using LL = long long;
using VI = vector<int>;

const int kMaxN = 3e5 + 7, kMoD = 100;

int m, a[kMaxN], b[kMaxN], c[kMaxN];

int lowbit(int x) { return x & (-x); }

void add(int x, int y) {
  for (int i = x; i <= m; i += lowbit(i)) {
    c[i] += y;
  }
}

int sum(int x) {
  int res = 0;
  for (int i = x; i; i -= lowbit(i)) {
    res += c[i];
  }
  return res;
}

signed main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    b[i] = a[i];
  }
  sort(b + 1, b + n + 1);
  m = unique(b + 1, b + n + 1) - b - 1;
  int ans = 0;
  for (int i = n; i; i--) {
    int k = lower_bound(b + 1, b + m + 1, a[i]) - b;
    (ans += sum(k - 1)) %= kMoD;
    add(k, 1);
  }
  cout << ans % kMoD;
  return 0;
}