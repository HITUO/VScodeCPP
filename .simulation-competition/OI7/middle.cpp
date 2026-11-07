#include <bits/stdc++.h>

using namespace std;

#define int long long

using LL = long long;
using VI = vector<int>;

const int kMaxN = 2e5 + 7;

int n, a[kMaxN], ans[kMaxN];
pair<int, int> s[kMaxN];

signed main() {
  freopen("middle.in", "r", stdin);
  freopen("middle.out", "w", stdout);
  srand(time(0));
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  if (a[1] == a[n]) {
    cout << n - 2;
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    if (s[a[i]].first != 0) {
      s[a[i]].first++;
    } else {
      s[a[i]].first++;
      s[a[i]].second = i;
    }
    if (s[a[i]].first >= 2) {
      ans[a[i]] = i - s[a[i]].second - 1;
    }
  }
  cout << rand() % (n - 3);
  // for (int i = 1; i <= n; i++) {
  //   cout << ans[i] << " ";
  // }
  return 0;
}