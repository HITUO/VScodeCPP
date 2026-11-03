#include <bits/stdc++.h>

using namespace std;

#define int long long

using LL = long long;
using VI = vector<int>;

const int kMaxN = 5e5 + 7;

int n, a[kMaxN], m, sum[kMaxN], ans = -1, cnt = -1;

bool check(int x, int i) {
  return a[i] * (i - x + 1) - (sum[i] - sum[x - 1]) <= m;
}

signed main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) {
    sum[i] = sum[i - 1] + a[i];
  }
  for (int i = 1; i <= n; i++) {
    cnt = 0;
    int l = 1, r = i;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (check(mid, i)) {
        cnt = mid;
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    ans = max(ans, i - cnt + 1);
  }
  cout << ans;
  return 0;
}