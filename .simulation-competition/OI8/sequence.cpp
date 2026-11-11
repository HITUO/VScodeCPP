#include <bits/stdc++.h>

using namespace std;

#define int long long

using LL = long long;
using VI = vector<int>;

const int kMaxN = 1e6 + 7;

struct V {
  int h, idx;
};

deque<V> q;
int n, k, a[kMaxN], b[kMaxN], ans, nw = 0;

signed main() {
  freopen("sequence.in", "r", stdin);
  freopen("sequence.out", "w", stdout);
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  for (int i = 1; i <= n; i++) {
    if (b[i] < a[i]) {
      cout << "-1";
      return 0;
    }
    while (!q.empty() && q.front().idx < i - k + 1) {
      nw -= q.front().h;
      q.pop_front();
    }
    int cha = b[i] - a[i], lv = 0;
    if (nw > cha) {
      lv = nw - cha;
      while (lv > 0) {
        int ths = min(lv, q.front().h);
        q.front().h -= ths;
        nw -= ths;
        lv -= ths;
        if (q.front().h == 0) {
          q.pop_front();
        }
      }
    } else if (nw < cha) {
      lv = cha - nw;
      ans += lv;
      nw = cha;
      if (!q.empty() && q.back().idx == i) {
        q.back().h += lv;
      } else {
        q.push_back({lv, i});
      }
    }
  }
  cout << ans;
  return 0;
}