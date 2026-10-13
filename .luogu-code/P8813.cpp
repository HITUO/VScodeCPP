#include <bits/stdc++.h>

using namespace std;

// #define int long long

using LL = long long;
using VI = vector<int>;

const int kMaxN = 2e5 + 7;

int a, b;
long long sum = 1;

signed main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> a >> b;
  if (a == 1) {
    cout << 1;
    return 0;
  } else if (b == 1) {
    cout << a;
    return 0;
  }
  for (int i = 1; i <= b; i++) {
    sum *= a;
    if (sum > 1e9) {
      cout << "-1";
      return 0;
    }
  }
  cout << sum;
  return 0;
}