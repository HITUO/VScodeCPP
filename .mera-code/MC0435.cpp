#include <bits/stdc++.h>

using namespace std;

#define int long long

using LL = long long;
using VI = vector<int>;

const int kMaxN = 1e3 + 7;

int n, m, q;
deque<int> a[kMaxN];

signed main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int x;
      cin >> x;
      a[i].push_back(x);
    }
  }
  cin >> q;
  for (int i = 1; i <= q; i++) {
    int opt, x, k;
    cin >> opt >> x >> k;
    k %= m;
    if (opt == 1) {
      for (int j = 1; j <= k; j++) {
        a[x].push_back(a[x].front());
        a[x].pop_front();
      }
    } else {
      for (int j = 1; j <= k; j++) {
        a[x].push_front(a[x].back());
        a[x].pop_back();
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    while (!a[i].empty()) {
      cout << a[i].front() << " ";
      a[i].pop_front();
    }
    cout << "\n";
  }
  return 0;
}