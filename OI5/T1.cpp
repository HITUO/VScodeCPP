#include <bits/stdc++.h>

using namespace std;

#define int long long

using LL = long long;
using VI = vector<int>;

const int kMaxN = 1e6 + 7;

string s1, s2, s3;
int n, ans = 0, a[kMaxN];
set<int> jiw;
VI d1, c1, dc1;
vector<pair<int, int>> hao;

signed main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> s1 >> s2 >> s3;
  n = s1.size();
  for (int i = 0; i < n; i++) {
    a[i] = s1[i] - '0' + s2[i] - '0';
    if (a[i] > 10) {
      jiw.insert(i);
      a[i] -= 10;
    }
  }
  for (auto i : jiw) {
    cout << i << " ";
  }
  cout << "\n";
  for (int i = 0; i < n; i++) {
    auto k = jiw.lower_bound(i);
    if (a[i] == s3[i] - '0' && k == jiw.end()) {
      hao.push_back({i, i});
    }
    if (a[i] == s3[i] - '0' && k != jiw.end() && i != 0) {
      d1.push_back(i);
    }
    if ((a[i] + 1) % 10 == s3[i] - '0' && k == jiw.end() && i != n - 1) {
      c1.push_back(i);
    }
    if ((a[i] + 1) % 10 == s3[i] - '0' && k != jiw.end() && i != n - 1) {
      dc1.push_back(i);
    }
  }
  // cout << "\n";
  // for (auto i : hao) {
  //   cout << i.first << " " << i.second << "\n";
  // }
  // cout << "\n";
  // for (int i : d1) {
  //   cout << i << " ";
  // }
  // cout << "\n";
  // for (int i : c1) {
  //   cout << i << " ";
  // }
  // cout << "\n";
  // for (int i : dc1) {
  //   cout << i << " ";
  // }
  // cout << "\n";
  for (int i = 0; i < c1.size(); i++) {
    int k = 1;
    while (binary_search(dc1.begin(), dc1.end(), c1[i] + k) == 1) {
      k++;
    }
    if (binary_search(d1.begin(), d1.end(), c1[i] + k) == 1) {
      hao.push_back({i, i + k});
    }
    // if ()
  }
  int cnt = 1;
  ans = 0;
  for (int i = 1; i < hao.size(); i++) {
    if (hao[i].first == hao[i - 1].second + 1) {
      cnt++;
    } else {
      ans += cnt * (1 + cnt) / 2;
      cnt = 1;
    }
  }
  cout << ans;
  // cout << isk(2, 2);
  return 0;
}

/*
这是T1的我的WA代码
请帮我调成AC代码
*/