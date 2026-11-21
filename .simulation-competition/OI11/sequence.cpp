#include <bits/stdc++.h>

using namespace std;

#define int long long

using LL = long long;
using VI = vector<int>;

const int kMaxN = 3e5 + 7;

int n, a[kMaxN], b[kMaxN], ans;

signed main() {
  freopen("sequence.in", "r", stdin);
  freopen("sequence.out", "w", stdout);
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    // b[i] = a[i] - b[i - 1];
    a[i] = a[i - 1] + (i % 2 == 0 ? x : -x);
    // if (b[i] == b[i - 1]) {
    //   ans--;
    // }
    // mp[b[i]]++;
  }
  // for (int i = 1; i <= n; i++) {
  //   if (mp.count(b[i])) {
  //     ans += mp[b[i]] * (mp[b[i]] - 1) / 2;
  //     mp[b[i]] = 0;
  //   }
  // }
  // for (int i = 1; i <= n; i++) {
  //   int sum = 0;
  //   for (int j = i; j <= n; j++) {
  //     sum = a[i] - a[j];
  //   }
  // }
  sort(a, a + 1 + n);
  int l = 0, r = 0;
  while (l <= n) {
    r = l + 1;
    while (r <= n && a[r] == a[l]) {
      r++;
    }
    int len = r - l;
    ans += len * (len - 1) / 2;
    l = r;
  }
  // for (int i = 1; i <= n; i++) {
  //   for (int j = 0; j < i - 1; j++) {
  //     if (b[i] == b[j]) {
  //       ans++;
  //     }
  //   }
  // }
  cout << ans;
  return 0;
}