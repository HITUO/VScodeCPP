#include <bits/stdc++.h>

using namespace std;

#define int long long

using LL = long long;
using VI = vector<int>;

const int kMaxN = 1e3 + 7;

class DealWithProblem {
private:
  int n, dp[kMaxN];
  [[nodiscard]] bool is_prime(int x) {
    if (x == 2) {
      return 1;
    }
    for (int i = 2; i * i <= x; i++) {
      if (!(x % i)) {
        return 0;
      }
    }
    return 1;
  }

public:
  DealWithProblem() : n(0), dp{} {}
  void get_ans() {
    cin >> n;
    dp[0] = 1;
    for (int i = 2; i <= n; i++) {
      if (!is_prime(i)) {
        continue;
      }
      for (int j = 0; j <= n; j++) {
        if (dp[j] && i + j <= n) {
          dp[i + j] += dp[j];
        }
      }
    }
    cout << dp[n];
  }
};

signed main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  DealWithProblem P1832;
  P1832.get_ans();
  return 0;
}