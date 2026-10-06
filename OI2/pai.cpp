#include <bits/stdc++.h>

using namespace std;

#define int long long

using LL = long long;
using VI = vector<int>;

const int kMaxN = 2e5 + 7;

signed main() {
  ios::sync_with_stdio(0), cin.tie(0);
  mt19937_64 rnd(time(0));
  int weishu = rnd() % 7 + 1;
  // cout << weishu;
  // weishu = 1;
  for (int i = 0; i < weishu; i++) {
    cout << char(rnd() % 9 + 'a');
  }
  return 0;
}