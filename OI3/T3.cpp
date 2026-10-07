// TODO:有问题

#include <bits/stdc++.h>

using namespace std;

#define int long long

using LL = long long;
using VI = vector<int>;

const int kMaxN = 2e5 + 7;

int n, l[kMaxN], r[kMaxN], l_l[kMaxN], l_r[kMaxN], t[kMaxN], a[kMaxN],
    ai = 0, l_a[kMaxN], la = 0, ans = -1e18;

signed main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> l[i] >> r[i];
    a[++ai] = l[i];
    a[++ai] = r[i];
  }
  sort(a + 1, a + n * 2 + 1);
  // for (int i = 1; i <= n * 2; i++) {
  //   cout << a[i] << " ";
  // }
  // cout << "\n";
  for (int i = 1; i <= n * 2; i++) {
    if (a[i] != a[i - 1]) {
      l_a[++la] = a[i];
    }
  }
  // for (int i = 1; i <= la; i++) {
  //   cout << l_a[i] << " ";
  // }
  // cout << "\n";
  for (int i = 1; i <= n; i++) {
    int re_l = lower_bound(l_a + 1, l_a + la + 1, l[i]) - l_a;
    l_l[i] = re_l;
    l_r[i] = lower_bound(l_a + 1, l_a + la + 1, r[i]) - l_a;
  }
  // for (int i = 1; i <= n; i++) {
  //   cout << l_l[i] << " ";
  // }
  // cout << "\n";
  // for (int i = 1; i <= n; i++) {
  //   cout << l_r[i] << " ";
  // }
  // cout << "\n";
  for (int i = 1; i <= n; i++) {
    t[l_l[i]]++;
    t[l_r[i] + 1]--;
  }
  for (int i = 1; i <= la; i++) {
    t[i] += t[i - 1];
  }
  // for (int i = 1; i <= la; i++) {
  //   cout << t[i] << " ";
  // }
  // cout << "\n";
  for (int i = 1; i <= la; i++) {
    ans = max(ans, t[i] * l_a[i]);
  }
  cout << ans;
  return 0;
}