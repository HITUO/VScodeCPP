#include <bits/stdc++.h>

using namespace std;

#define int long long

using LL = long long;
using VI = vector<int>;

const int kMaxN = 3e4 + 7;

int n, m1, m2, s[kMaxN], yngsh[kMaxN], ans = INT_MAX, t = 0;

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
  cin >> n >> m1 >> m2;
  if (m1 == 2) {
    t = 1;
    yngsh[1] = 2;
  } else {
    if (m1 == 3) {
      t = 1;
      yngsh[1] = 3;
    } else {
      for (int i = 2; i <= m1; i++) {
        if (m1 % i == 0 && is_prime(i)) {
          t++;
          yngsh[t] = i;
        }
      }
    }
  }
  int tp = 0;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
    bool f = 1;
    for (int j = 1; j <= t; j++) {
      if (s[i] % yngsh[j] != 0) {
        f = 0;
        tp++;
        break;
      }
    }
    if (f == 0 || __gcd(s[i], m1) == 1) {
      continue;
    }
    int kk = __gcd(s[i], m1), cnt = 1;
    while (kk % m1 != 0) {
      kk *= __gcd(s[i], m1);
      cnt++;
    }
    ans = min(ans, cnt * m2 * 1LL);
  }
  if (tp == n) {
    cout << "-1";
  } else {
    cout << ans;
  }
  return 0;
}