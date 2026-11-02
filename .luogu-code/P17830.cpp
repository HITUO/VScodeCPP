#include <bits/stdc++.h>

using namespace std;

#define int long long

using LL = long long;
using VI = vector<int>;

const int kMaxN = 5e5 + 7;

int n, m, a[kMaxN], ans[kMaxN];

signed main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    VI vis(m + 1, -1), pd(n + 1, 0);
    int tail = 0;
    for (int j = i; j <= n; j++) {
      if (vis[a[j]] != -1) {
        int pos = vis[a[j]];
        for (int k = pos + 1; k <= tail; k++) {
          vis[pd[k]] = -1;
        }
        tail = pos;
      } else {
        pd[++tail] = a[j];
        vis[a[j]] = tail;
      }
    }
    for (int j = 1; j <= tail; j++) {
      ans[pd[j]]++;
    }
  }
  for (int i = 1; i <= m; i++) {
    cout << ans[i] << " ";
  }
  return 0;
}