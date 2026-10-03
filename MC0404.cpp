#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using VI = vector<int>;

const int kMaxN = 2e5 + 7;

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  string s;
  int x, y;
  x = y = 0;
  cin >> s;
  for (int i = 0; i < (int)s.size(); i++) {
    if (s[i] == 'U')
      y++;
    if (s[i] == 'D')
      y--;
    if (s[i] == 'L')
      x--;
    if (s[i] == 'R')
      x++;
  }
  cout << x << " " << y;
  return 0;
}