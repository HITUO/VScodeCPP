#include <bits/stdc++.h>

using namespace std;

#define int long long

using LL = long long;
using VI = vector<int>;

const int kMaxN = 3e5 + 7;

int n, a[kMaxN];
map<int, int> m;

signed main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    m[a[i]]++;
  }
  for (int i = 1; i <= n; i++) {
    cout << m[a[i]] - 1 << " ";
  }
  return 0;
}