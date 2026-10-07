#include <bits/stdc++.h>

using namespace std;

#define int long long

using LL = long long;
using VI = vector<int>;

const int kMaxN = 2e5 + 7;

int n, k, p;

signed main() {
  ios::sync_with_stdio(0), cin.tie(0);
  mt19937_64 rnd(time(0));
  n = rnd() % 10000 + 1;
  n = 10000;
  p = rnd() % 10000 + 1;
  k = rnd() % p + 1;
  cout << n << " " << p << " " << k << "\n";
  for (int i = 1; i <= n; i++) {
    cout << rnd() % 100000 + 1 << "\n";
  }
  return 0;
}