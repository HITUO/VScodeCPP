#include <bits/stdc++.h>

using namespace std;

#define int long long

using LL = long long;
using VI = vector<int>;

const int kMaxN = 2e5 + 7;

int n, ans;

bool is_prime(int x) {
  if (x == 1) {
    return 0;
  }
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      return 0;
    }
  }
  return 1;
}

signed main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for (int i = 2; i <= n; i++) {
    if (is_prime(i) && is_prime(n - i)) {
      ans++;
    }
  }
  cout << ceil(ans / 2.0);
  return 0;
}