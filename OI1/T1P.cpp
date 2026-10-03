#include <bits/stdc++.h>

using namespace std;

#define int long long

using LL = long long;
using VI = vector<int>;

const int kMaxN = 4e5 + 7;

int a[kMaxN], s[kMaxN], ai, cnt;

signed main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  while (cin >> a[++ai]) {
  }
  fill(s, s + kMaxN, 0);
  cnt = 1;
  s[1] = a[1];
  for (int i = 2; i <= ai; i++) {
    if (a[i] <= s[cnt]) {
      s[++cnt] = a[i];
    } else {
      int l = 1, r = cnt;
      while (l < r) {
        int mid = (l + r) / 2;
        if (a[i] > s[mid]) {
          r = mid;
        } else {
          l = mid + 1;
        }
      }
      s[l] = a[i];
    }
  }
  cout << cnt - 1 << "\n";
  fill(s, s + kMaxN, 0);
  cnt = 1;
  s[1] = a[1];
  for (int i = 2; i <= ai; i++) {
    if (a[i] > s[cnt]) {
      s[++cnt] = a[i];
    } else {
      int l = 1, r = cnt;
      while (l < r) {
        int mid = (l + r) / 2;
        if (a[i] <= s[mid]) {
          r = mid;
        } else {
          l = mid + 1;
        }
      }
      s[l] = a[i];
    }
  }
  cout << cnt;
  return 0;
}