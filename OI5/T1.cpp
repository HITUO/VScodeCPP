#include <bits/stdc++.h>

using namespace std;

#define int long long

using LL = long long;
using VI = vector<int>;

const int kMaxN = 2e5 + 7;

string s1, s2, s3;
int n, ans = 0;

bool isk(int x, int y) { // [x, y]
  int jiw = 0;
  for (int i = y - 1; i >= x - 1; i--) {
    if ((s1[i] - '0' + s2[i] - '0' + jiw) % 10 != s3[i] - '0') {
      return 0;
    }
    int k = s1[i] - '0' + s2[i] - '0' + jiw;
    jiw = k / 10;
  }
  return 1;
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