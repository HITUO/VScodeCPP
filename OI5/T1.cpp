#include <bits/stdc++.h>

using namespace std;

#define int long long

using LL = long long;
using VI = vector<int>;

const int kMaxN = 2e5 + 7;

string s1, s2, s3;
int n, ans = 0;

bool isk(int x, int y) { // [x, y]
  __int128 sum1 = 0, sum2 = 0, sum3 = 0;
  for (int i = x; i <= y; i++) {
    sum1 *= 10;
    sum1 += s1[i - 1] - '0';
  }
  for (int i = x; i <= y; i++) {
    sum2 *= 10;
    sum2 += s2[i - 1] - '0';
  }
  for (int i = x; i <= y; i++) {
    sum3 *= 10;
    sum3 += s3[i - 1] - '0';
  }
  // cout << sum1 << " " << sum2 << " " << sum3 << "\n";
  if (sum1 == sum3 - sum2) {
    return 1;
  }
  return 0;
}

signed main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> s1 >> s2 >> s3;
  n = s1.size();
  for (int i = 1; i <= n; i++) {
    if (s1[i - 1] - '0' + s2[i - 1] - '0' > s3[i - 1] - '0') {
      continue;
    }
    if (s1[i - 1] - '0' + s2[i - 1] - '0' < s3[i - 1] - '0' - 1) {
      continue;
    }
    for (int j = i; j <= n; j++) {
      if ((s1[j - 1] - '0' + s2[j - 1] - '0') % 10 != s3[j - 1] - '0') {
        continue;
      }
      // cout << "i = " << i << "  j = " << j << "   isk = " << isk(i, j) <<
      // "\n";
      if (isk(i, j)) {
        ans++;
      }
    }
  }
  cout << ans;
  // cout << isk(2, 2);
  return 0;
}