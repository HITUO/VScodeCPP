#include <bits/stdc++.h>
using namespace std;
bool vis[10000001];
int prime[1000010];
int wei[10][10];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  //	freopen("alphametic.in", "r", stdin);
  //	freopen("alphametic.out", "w", stdout);
  string s;
  cin >> s;
  int n = (int)s.size();
  if (n == 1) {
    cout << 2 << "\n";
    return 0;
  }
  if (n == 2) {
    if (s[0] != s[1]) {
      cout << "13" << "\n";
      return 0;
    } else {
      cout << "11" << "\n";
      return 0;
    }
  }
  bool deng = 1;
  for (int i = 1; i < n; i++) {
    if (s[i] != s[i - 1])
      deng = 0;
  }
  if (deng) {
    cout << "-1" << "\n";
    return 0;
  }
  if (n == 3) {
    if (s[0] != s[1] && s[1] != s[2] && s[0] != s[2]) {
      cout << "103\n";
      return 0;
    }
    if (s[0] == s[1]) {
      cout << "113\n";
      return 0;
    }
    if (s[0] == s[2]) {
      cout << "101\n";
      return 0;
    }
    if (s[1] == s[2]) {
      cout << "199\n";
      return 0;
    }
  }
  if (n == 4) {
    if (s[0] != s[1] && s[1] != s[2] && s[2] != s[3] && s[0] != s[3] &&
        s[0] != s[2] && s[1] != s[3]) {
      cout << "1039\n";
      return 0;
    }
    if (s[0] == s[1] && s[1] != s[2] && s[2] != s[3] && s[3] != s[0] &&
        s[0] != s[2] && s[1] != s[3]) {
      cout << "1103\n";
      return 0;
    }

    if (s[0] != s[1] && s[1] == s[2] && s[2] != s[3] && s[3] != s[0] &&
        s[0] != s[2] && s[1] != s[3]) {
      cout << "1009\n";
      return 0;
    }
    if (s[0] != s[1] && s[1] != s[2] && s[2] == s[3] && s[3] != s[0] &&
        s[0] != s[2] && s[1] != s[3]) {
      cout << "1033\n";
      return 0;
    }
    if (s[0] != s[1] && s[1] != s[2] && s[2] != s[3] && s[3] == s[0] &&
        s[0] != s[2] && s[1] != s[3]) {
      cout << "1021\n";
      return 0;
    }
    if (s[0] != s[1] && s[1] != s[2] && s[2] != s[3] && s[3] != s[0] &&
        s[0] == s[2] && s[1] != s[3]) {
      cout << "1013\n";
      return 0;
    }
    if (s[0] != s[1] && s[1] != s[2] && s[2] != s[3] && s[3] != s[0] &&
        s[0] != s[2] && s[1] == s[3]) {
      cout << "1303\n";
      return 0;
    }
    if (s[0] == s[1] && s[1] == s[2] && s[2] != s[3] && s[3] != s[0] &&
        s[0] != s[2] && s[1] != s[3]) {
      cout << "1117\n";
      return 0;
    }
    if (s[0] != s[1] && s[1] == s[2] && s[2] == s[3] && s[3] != s[0] &&
        s[0] != s[2] && s[1] != s[3]) {
      cout << "1777\n";
      return 0;
    }
    if (s[0] == s[1] && s[1] != s[2] && s[2] != s[3] && s[3] != s[0] &&
        s[0] != s[2] && s[1] != s[3]) {
      cout << "1039\n";
      return 0;
    }
    if (s[0] != s[1] && s[1] != s[2] && s[2] != s[3] && s[3] != s[0] &&
        s[0] == s[2] && s[1] == s[3]) {
      cout << "-1\n";
      return 0;
    }
  }
  if (n == 6) {
    if (s[0] == s[1] && s[1] == s[2] && s[3] == s[4] && s[4] == s[5] &&
        s[5] == s[6]) {
      cout << "-1\n";
    }
  }
  int cnt = 0;
  int ji = 0;
  for (int i = 2; i <= pow(10, n); i++) {
    if (!vis[i]) {
      prime[++cnt] = i;
    }
    for (int j = 1; j <= cnt && i * prime[j] <= pow(10, n); j++) {
      vis[i * prime[j]] = 1;
      if (i % prime[j] == 0)
        break;
    }
  }
  for (int i = 1; i <= cnt; i++) {
    if (prime[i] >= pow(10, n - 1)) {
      ji = i;
      break;
    }
  }
  bool ch = 1;
  for (int i = ji; i <= cnt; i++) {
    ch = 1;
    for (int j = 0; j < n; j++)
      for (int k = j + 1; k < n; k++) {
        int wj = (prime[i] / (int)pow(10, n - j - 1)) % 10;
        int wk = (prime[i] / (int)pow(10, n - k - 1)) % 10;
        if (s[j] == s[k] && wj != wk)
          ch = 0;
        if (s[j] != s[k] && wj == wk) {
          ch = 0;
        }
      }
    if (ch) {
      cout << prime[i] << "\n";
      break;
    }
  }
  if (!ch)
    cout << "-1\n";
  return 0;
}