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
  cout << 1 << "\n";
  int n = rnd() % 500;
  int k = rnd() % n;
  cout << n << " " << k << "\n";
  for (int i = 0; i < n; i++) {
    cout << rnd() % (n + 10) << " ";
  }
  return 0;
}