#include <bits/stdc++.h>

using namespace std;

#define int long long

using LL = long long;
using VI = vector<int>;

const int kMaxN = 1e7 + 7;

bool vis[kMaxN];
int prime[1000007];
string s;
int tot = 0, n;

signed main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> s;
  n = s.size();
  // fill(vis, vis + kMaxN, 0);
  // int kn = pow(10, n);
  // for (int i = 2; i <= kn; i++) {
  //   if (!vis[i]) {
  //     prime[++tot] = i;
  //   }
  //   for (int j = 1; j <= tot && i * prime[j] <= kn; j++) {
  //     vis[i * prime[j]] = 1;
  //     if (i % prime[j] == 0) {
  //       break;
  //     }
  //   }
  // }
  // // cout << tot << "\n";
  // // for (int i = 1; i <= tot; i++) {
  // //   cout << prime[i] << " ";
  // // }
  // // cout << "\n";
  // vector<VI> ton(tot + 1, VI(n + 1, 0));
  // for (int i = 1; i <= tot; i++) {
  //   VI st;
  //   VI num;
  //   int t = prime[i];
  //   while (t > 0) {
  //     int wei = t % 10;
  //     num.push_back(wei);
  //     t /= 10;
  //   }
  //   reverse(num.begin(), num.end());
  //   int sum = 0;
  //   for (int j = 0; j < num.size(); j++) {
  //     bool f = 0;
  //     for (int k = 0; k < st.size(); k++) {
  //       if (st[k] == num[j]) {
  //         f = 1;
  //         break;
  //       }
  //     }
  //     if (st.empty() || f == 0) {
  //       ton[i][j + 1] = ++sum;
  //       st.push_back(num[j]);
  //     } else {
  //       int find_num;
  //       for (int k = 0; k < st.size(); k++) {
  //         if (st[k] == num[j]) {
  //           find_num = k + 1;
  //           break;
  //         }
  //       }
  //       ton[i][j + 1] = ton[i][find_num];
  //     }
  //   }
  //   // for (int j : wei) {
  //   //   cout << j << " ";
  //   // }
  //   // cout << "\n";
  // }
  // vector<pair<int, int>> ans;
  // // for (int i = 1; i <= tot; i++) {
  // //   for (int j = 1; j <= n; j++) {
  // //     cout << ton[i][j] << " ";
  // //   }
  // //   cout << "\n";
  // // }
  // for (int i = 1; i <= tot; i++) {
  //   int tt = 0;
  //   for (int j = 1; j <= n && ton[i][j] != 0; j++) {
  //     tt *= 10;
  //     tt += ton[i][j];
  //   }
  //   ans.push_back({tt, prime[i]});
  // }
  // sort(ans.begin(), ans.end());
  // vector<pair<int, int>> t_ans;
  // for (int i = 0; i < ans.size(); i++) {
  //   if (i == 0 || ans[i] != ans[i - 1]) {
  //     t_ans.push_back(ans[i]);
  //   }
  // }
  // for (auto i : t_ans) {
  //   cout << i.first << " ";
  // }
  vector<char> ss;
  string kk = "";
  int sum = 0;
  for (int i = 0; i < s.size(); i++) {
    int f = 0;
    bool ff = 0;
    for (int j = 0; j < ss.size(); j++) {
      if (ss[j] == s[i]) {
        f = j;
        ff = 1;
        break;
      }
    }
    if (ff == 0) {
      kk += ++sum + '0';
      ss.push_back(s[i]);
    } else {
      kk += kk[f];
    }
  }
  int anss = 0;
  for (int i = 0; i < kk.size(); i++) {
    anss *= 10;
    anss += kk[i] - '0';
  }
  cout << anss;

  // for (int i = 0; i < t_ans.size(); i++) {
  //   if (anss == t_ans[i].first) {
  //     cout << t_ans[i].second;
  //     return 0;
  //   }
  // }
  // cout << "-1";
  return 0;
}