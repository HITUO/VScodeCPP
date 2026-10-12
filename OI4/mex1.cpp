#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[200010], b[200010];
int chong[200010], mex[200010];
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  //	freopen("mex.in", "r", stdin);
  //	freopen("mex.out", "w", stdout);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
      b[i] = 0;
    }
    int ji = 0, d = 1, c = 0, kl = 0;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      if (a[i] == k)
        kl++;
      if (a[i] < k) {
        d++;
        b[a[i]]++;
        if (b[a[i]] > 1) {
          c++;
        }
      }
    }
    sort(a + 1, a + 1 + n);
    if (k > n + 1 || a[n] < k - 1) {
      cout << "-1\n";
      continue;
    }
    if (a[n] < k && c != 0) {
      cout << "-1\n";
      continue;
    }
    int ans = 0, e = 0;
    for (int i = 1; i < k; i++) {
      if (b[i] == 0) {
        mex[++e] = i;
      }
    }
    if (e == 0) {
      cout << kl << "\n";
      continue;
    }
    int l = 1;
    if (c) {
      for (int i = 1; a[i] < k; i += b[a[i]]) {
        if (b[a[i]] > 1) {
          for (int j = l; j <= e; j++) {
            if (mex[j] < a[i] && b[a[i]] > 1) {
              l++;
              ans += a[i] - mex[j];
              b[a[i]]--;
            } else
              break;
          }
        }
      }
    }
    for (int i = l; i <= e; i++) {
      ans += a[d++] - mex[i];
    }
    cout << ans << "\n";
  }
  return 0;
}
