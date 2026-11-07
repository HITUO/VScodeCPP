#include <bits/stdc++.h>

using namespace std;

#define int long long

using LL = long long;
using VI = vector<int>;

const int kMaxN = 8e3 + 7;

int T, n;
VI a;
set<string> st;

void dfs(int l, int r, string s) {
  if (l >= r) {
    if (st.count(s)) {
      st.insert(s);
    }
    return;
  }
  int ll = l, rr = r;
  for (int i = l; i <= r; i++) {
    for (int j = l + 1; j <= r; j++) {
      if (s[i] == s[j]) {
        dfs(l + 1, r - 1, s);
      } else {
        string t;
        t += s[n - 1];
        t += s.substr(1, n - 2);
        t += s[0];
        dfs(l + 1, r - 1, t);
        dfs(l + 1, r - 1, s);
      }
    }
  }
}

signed main() {
  ios::sync_with_stdio(0), cin.tie(0);
  freopen("rhythm.in", "r", stdin);
  freopen("rhythm.out", "w", stdout);
  cin >> T;
  while (T--) {
    cin >> n;
    string s;
    st.clear();
    a.resize(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      s += a[i] + '0';
    }
    st.insert(s);
    vector<pair<int, int>> p;
    if (n == 1) {
      cout << "1\n";
      return 0;
    }
    // for (int i = 1; i <= n; i++) {
    //   for (int j = i + 1; j <= n; j++) {
    //     if (a[i] != a[j]) {
    //       p.push_back({i, j});
    //     }
    //   }
    // }
    dfs(0, n - 1, s);
    cout << st.size() << "\n";
  }
  return 0;
}

/*

*/