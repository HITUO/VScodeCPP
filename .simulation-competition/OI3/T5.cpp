#include <bits/stdc++.h>

using namespace std;

#define int long long

using LL = long long;
using VI = vector<int>;

const int kMaxN = 5e4 + 7, kMaxM = 1e6 + 7;

int n, a[kMaxN], b[kMaxN], t[kMaxM], l, r;
vector<pair<int, int>> ans;

signed main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i];
    t[a[i]]++;
    t[b[i]]--;
  }
  for (int i = 1; i < kMaxM; i++) {
    t[i] += t[i - 1];
  }
  // for (int i = 1; i <= 12; i++) {
  //   cout << t[i] << " ";
  // }
  l = r = -1;
  for (int i = 1; i < kMaxM; i++) {
    if (i == 1) {
      if (t[i] >= 1) {
        l = i;
      }
      continue;
    }
    if (t[i] == 0) {
      if (l != -1) {
        ans.push_back({l, i});
        l = r = -1;
      }
    } else {
      if (l == -1) {
        l = i;
      } else {
        r = i + 1;
      }
    }
  }
  sort(ans.begin(), ans.end());
  for (auto i : ans) {
    cout << i.first << " " << i.second << "\n";
  }
  return 0;
}