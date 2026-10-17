#include <bits/stdc++.h>

using namespace std;

#define int long long
using LL = long long;

signed main() {
  ios::sync_with_stdio(false), cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  LL base = 0;
  for (int i = 0; i < n; i++) {
    base += (i + 1);
  }
  vector<LL> weight;
  weight.reserve(m);
  for (int i = 0; i < m; i++) {
    int l;
    cin >> l;
    LL w = 0;
    for (int j = 0; j < l; j++) {
      int x;
      cin >> x;
      int pos = upper_bound(a.begin(), a.end(), x) - a.begin();
      w += n - pos;
    }
    weight.push_back(w);
  }
  sort(weight.begin(), weight.end());
  LL ans = m * base;
  for (int i = 0; i < m; i++) {
    LL coeff = m - i;
    ans += weight[i] * coeff;
  }
  cout << ans << endl;
  return 0;
}