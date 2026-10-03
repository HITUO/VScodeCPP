#include <bits/stdc++.h>

using namespace std;

#define int long long

using LL = long long;
using VI = vector<int>;

const int kMaxN = 2e5 + 7;

int n, ans = INT_MIN;
string s;

signed main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> s;
  for (int i = 0; i < n; i++) {
    int b = 0, r = 0;
    for (int j = 0; j < n; j++) {
      if (s[(i - j + n) % n] == 'b') {
        break;
      }
      r++;
    }
    for (int j = 0; j < n; j++) {
      if (s[(i - j + n) % n] == 'r') {
        break;
      }
      b++;
    }
    int t = max(b, r);
    b = r = 0;
    for (int j = 1; j <= n; j++) {
      if (s[(i + j) % n] == 'b') {
        break;
      }
      r++;
    }
    for (int j = 1; j <= n; j++) {
      if (s[(i + j) % n] == 'r') {
        break;
      }
      b++;
    }
    ans = max(ans, t + max(r, b));
  }
  cout << min(ans, n);
  return 0;
}