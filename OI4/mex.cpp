#include <bits/stdc++.h>

using namespace std;

#define int long long

using LL = long long;
using VI = vector<int>;

const int kMaxN = 2e5 + 7;

int T, n, k, a[kMaxN], vis[kMaxN], ans;

signed main() {
  ios::sync_with_stdio(0), cin.tie(0);
  freopen("mex.in", "r", stdin);
  freopen("mex.out", "w", stdout);
  cin >> T;
  while (T--) {
    cin >> n >> k;
    VI trsh, v_t;
    map<int, int> m;
    ans = 0;
    for (int i = 0; i < k; i++) {
      vis[i] = 0;
    }
    int biyong = -1, biyongshu = 0;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      if (a[i] == k) {
        biyongshu++;
        m[k]++;
        // continue;
      }
      if (a[i] >= k) {
        trsh.push_back(a[i]);
        v_t.push_back(1);
        continue;
      }
      if (m.count(a[i]) == 1 && m[a[i]] > 0) {
        trsh.push_back(a[i]);
        v_t.push_back(1);
      }
      m[a[i]]++;
    }
    if (n < k - 1) {
      cout << -1 << "\n";
      continue;
    }
    int ff = 1;
    for (int i = 1; i < k; i++) {
      if (!m.count(i)) {
        ff = 0;
      }
    }
    // cout << "biyongshu = " << biyongshu << "\n";
    if (ff) {
      if (m.count(k)) {
        ans += biyongshu;
        cout << ans << "\n";
        continue;
      } else {
        cout << "0\n";
        continue;
      }
    }
    sort(trsh.begin(), trsh.end());
    reverse(trsh.begin(), trsh.end());
    // if (biyong != -1) {
    //   for (int i = k - 1; i > 0 && biyongshu > 0; i--) {
    //     if (m.count(i) == 0) {
    //       ans += biyong - i;
    //       biyongshu--;
    //       m[i] = 1;
    //     }
    //   }
    //   if (biyongshu > 0) {
    //     ans += biyongshu;
    //     biyongshu = 0;
    //   }
    // }
    // cout << ans << "\n";
    // for (auto i : trsh) {
    //   cout << i << " ";
    // }
    // cout << "\n";
    bool exitt = 0;
    for (int i = 1; i < k; i++) {
      if (m.count(i) == 0) {
        while (trsh.back() <= i) {
          trsh.pop_back();
        }
        if (trsh.empty()) {
          cout << "-1\n";
          exitt = 1;
          break;
        }
        ans += trsh.back() - i;
        trsh.pop_back();
      }
    }
    if (exitt) {
      continue;
    }
    cout << ans << "\n";
  }
  return 0;
}