#include <bits/stdc++.h>

using namespace std;

#define int long long

using LL = long long;
using VI = vector<int>;

const int kMaxN = 1e3 + 7;

int n, k, answer;
VI ans;
string a[4];
// char a[4][kMaxN];

int get_num(int x) {
  if (x + 2 > n) {
    return -2;
  }
  string s1 = "", s2 = "", s3 = "";
  s1 = a[1].substr(x - 1, 3);
  s2 = a[2].substr(x - 1, 3);
  s3 = a[3].substr(x - 1, 3);
  // cout << s1 << "\n" << s2 << "\n" << s3 << "\n\n";
  if (s1 == "---" && s2 == "-o-" && s3 == "---") {
    return 1;
  } else if (s1 == "o--" && s2 == "---" && s3 == "--o") {
    return 2;
  } else if (s1 == "o--" && s2 == "-o-" && s3 == "--o") {
    return 3;
  } else if (s1 == "o-o" && s2 == "---" && s3 == "o-o") {
    return 4;
  } else if (s1 == "o-o" && s2 == "-o-" && s3 == "o-o") {
    return 5;
  } else if (s1 == "o-o" && s2 == "o-o" && s3 == "o-o") {
    return 6;
  }
  return -1;
}

signed main() {
  freopen("dice.in", "r", stdin);
  freopen("dice.out", "w", stdout);
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= 3; i++) {
    // string t;
    // cin >> t;
    // for (int j = 0; j < t.size(); j++) {
    //   a[i][j] = t[j];
    // }
    cin >> a[i];
  }
  for (int i = 1; i <= n - 2; i++) {
    int k = get_num(i);
    if (k == -2 || k == -1) {
      continue;
    }
    ans.push_back(k);
    i += 2;
  }
  sort(ans.begin(), ans.end());
  // for (auto i : ans) {
  //   cout << i << " ";
  // }
  for (auto i : ans) {
    if (i <= 3 && k > 0) {
      k--;
      answer += 7 - i;
      continue;
    }
    answer += i;
  }
  cout << answer;
  // cout << get_num(4);
  return 0;
}