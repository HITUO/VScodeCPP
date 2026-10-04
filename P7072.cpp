#include <bits/stdc++.h>

using namespace std;

#define int long long

using LL = long long;
using VI = vector<int>;

const int kMaxN = 2e5 + 7;

int n, w, ton[610];

signed main() {
  ios::sync_with_stdio(0), cin.tie(0);
  fill_n(ton, 610, 0);
  cin >> n >> w;
  for (int i = 1; i <= n; i++) {
    int p, num = max(1LL, (i * w / 100));
    cin >> p;
    ton[p]++;
    int ret = -1;
    for (int j = 600; j >= 0; j--) {
      if (num <= 0) {
        break;
      }
      if (ton[j] == 0) {
        continue;
      }
      num -= ton[j];
      ret = j;
    }
    cout << ret << " ";
  }
  return 0;
}