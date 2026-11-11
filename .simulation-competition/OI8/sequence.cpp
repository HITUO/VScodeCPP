#include <bits/stdc++.h>

using namespace std;

#define int long long

using LL = long long;
using VI = vector<int>;

const int kMaxN = 1e6 + 7;

int n, k, a[kMaxN], b[kMaxN], cnt[kMaxN], ans;

signed main() {
  // freopen("sequence.in", "r", stdin);
  // freopen("sequence.out", "w", stdout);
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  for (int i = 1; i <= n; i++) {
    if (b[i] < a[i]) {
      cout << "-1";
      return 0;
    }
    if (b[i] == a[i]) {
      continue;
    }
    int cha = b[i] - a[i];
    if (cha < cnt[i - 1]) {
      cnt[i] = cha;
      continue;
    }
    cha -= cnt[i - 1];
    ans += cha;
    cnt[i] = cha + cnt[i - 1];
  }
  cout << ans;
  return 0;
}