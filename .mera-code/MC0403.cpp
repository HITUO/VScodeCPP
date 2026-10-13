#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using VI = vector<int>;

const int kMaxN = 1e5 + 7;

int n, a[kMaxN], b[kMaxN], suma = 0, sumb = 0;

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i], (suma += a[i]) %= 10;
  for (int i = 1; i <= n; i++)
    cin >> b[i], (sumb += b[i]) %= 10;
  int c = (suma * sumb) % 10;
  cout << (c % 2 ? "odd" : "even");
  return 0;
}