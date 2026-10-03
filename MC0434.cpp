#include <bits/stdc++.h>

using namespace std;

#define int long long

using LL = long long;
using VI = vector<int>;

const int kMaxN = 1e6 + 7;

struct V {
  int data, idx, ans;
} a[kMaxN];

int n, b[kMaxN];

bool cmp(V x, V y) { return x.data < y.data; }

signed main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].data;
    a[i].idx = i;
  }
  sort(a + 1, a + n + 1, cmp);
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i].data == a[i - 1].data) {
      a[i].ans = cnt;
    } else {
      cnt = i;
      a[i].ans = cnt;
    }
    b[a[i].idx] = a[i].ans;
  }
  for (int i = 1; i <= n; i++) {
    cout << b[i] << " ";
  }
  return 0;
}