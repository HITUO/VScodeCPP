#include <bits/stdc++.h>

using namespace std;

#define int long long

#define REP(i, a, b) for (int i = (a); i <= (int)(b); i++)
using LL = long long;
using VI = vector<int>;

const int kMaxN = 2e5 + 7;

signed main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  mt19937_64 rnd(time(0));
  int n = rnd() % 10, k = rnd() % n;
  cout << n << " " << k << "\n";
  REP(i, 1, n) cout << (rnd() % 2 ? "X" : "Y");
  return 0;
}