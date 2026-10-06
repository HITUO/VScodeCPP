#include <bits/stdc++.h>

using namespace std;

#define int long long

using LL = long long;
using VI = vector<int>;

const int kMaxN = 2e5 + 7;

signed main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  for (int i = 2; i * i <= 111211; i++) {
    if (111211 % i == 0) {
      cout << "No";
      return 0;
    }
  }
  cout << "Yes";
  return 0;
}