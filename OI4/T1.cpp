#include <bits/stdc++.h>

using namespace std;

#define int long long

using LL = long long;
using VI = vector<int>;

const int kMaxN = 2e5 + 7;

int T, n, k, a[kMaxN], vis[kMaxN], ans;

int lower_bb(VI &duo, VI &duoshu, int x) {
  int l = 0, r = duo.size() - 1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (duo[mid] == x && duoshu[mid] > 0) {
      duoshu[mid]--;
      return mid;
    }
    if (duo[mid] == x && duoshu[mid] == 0) {
      int r_len = mid + 1, r_f = 0;
      while (r_len < n && duoshu[r_len] == 0) {
        r_len++;
      }
      if (r_len >= 0 && duoshu[r_len] > 0) {
        r_f = 1;
      }
      if (r_f) {
        duoshu[r_len]--;
        return r_len;
      }
    }
    if (duo[mid] < x) {
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  return -1;
}

signed main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> T;
  while (T--) {
    cin >> n >> k;
    map<int, int> m;
    VI duo, cha, duoshu;
    ans = 0;
    for (int i = 0; i < k; i++) {
      vis[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      m[a[i]]++;
    }
    if (n < k) {
      cout << "-1\n";
      continue;
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i < k; i++) {
      if (m.count(i)) {
        if (m[i] > 1) {
          duo.push_back(i);
          duoshu.push_back(m[i] - 1);
        }
        m[i] = 0;
      } else {
        cha.push_back(i);
      }
    }
    bool f = 0;
    int biyong = -1, biyongshu = -1;
    for (int i = k; i <= n; i++) {
      if (f == 1 && m.count(i)) {
        if (m[i] > 1) {
          duo.push_back(i);
          duoshu.push_back(m[i] - 1);
        }
        m[i] = 0;
        continue;
      }
      if (m.count(i) == 0) {
        f = 1;
        continue;
      } else {
        biyong = i;
        biyongshu = m[i];
      }
    }
    if (biyong == -1) {
      for (int i = 0; i < cha.size(); i++) {
        int kk = lower_bb(duo, duoshu, cha[i]);
        ans += duo[kk] - cha[i];
      }
    } else {
      while (biyongshu > 0) {
        ans += biyong - cha.back();
        cha.pop_back();
      }
      for (int i = 0; i < cha.size(); i++) {
        int kk = lower_bb(duo, duoshu, cha[i]);
        ans += duo[kk] - cha[i];
      }
    }
    cout << ans << "\n";
  }
  return 0;
}