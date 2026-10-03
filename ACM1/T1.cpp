#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for (int i = (a); i <= (int)(b); i++)
#define int long long
const int kMaxN = 2e5 + 7;
int n, k, cnt = 1e9, dis1[kMaxN], dis2[kMaxN], sd[kMaxN], nn;
map<int, vector<int>> ton;
bool f[kMaxN];
string s, ss;
signed main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> k >> s;
  if (n == 1)
    return cout << "0", 0;
  nn = n;
  ss = s;
  //	fill(dis1, dis + kMaxN, INT_MAX);
  fill(f, f + kMaxN, 0);
  for (int i = 0; i < n; i++) {
    if (s[i] == 'X') {
      dis1[i] = cnt;
    } else {
      dis1[i] = 1e9 + 100;
      cnt = 0;
    }
    if (cnt != 1e9)
      cnt++;
  }
  cnt = 1e9;
  for (int i = n - 1; i >= 0; i--) {
    if (s[i] == 'X') {
      dis2[i] = cnt;
    } else {
      dis2[i] = 1e9 + 100;
      cnt = 0;
    }
    if (cnt != 1e9)
      cnt++;
  }
  for (int i = 0; i < n; i++) {
    sd[i] = dis1[i] + dis2[i];
  }
  //	for (int i = 0; i < n; i++) {
  //		cout << sd[i] << " ";
  //	}
  //	cout<<"\n\n\n";
  for (int i = 0; i < n; i++) {
    if (s[i] == 'X') {
      ton[sd[i]].push_back(i);
    }
  }
  sort(sd, sd + n);
  int len = unique(sd, sd + n) - sd;
  n = len;
  for (int i = 0; i < n; i++) {
    if (sd[i] > 2e9)
      break;
    for (int j = 0; j < (int)ton[sd[i]].size(); j++) {
      //			cout<<sd[i]<<" "<<k<<"\n";
      if (k > 0)
        k--;
      else
        break;
      f[ton[sd[i]][j]] = 1;
    }
  }
  for (int i = 0; i < s.size(); i++)
    if (f[i] == 1)
      s[i] = 'Y';
  //  	cout<<s<<"\n";
  int tt = 0, ans = 0;
  if (k <= 0) {
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == 'Y') {
        tt++;
      } else {
        ans += max(tt - 1, 0ll);
        tt = 0;
      }
    }
    ans += max(tt - 1, 0ll);
  }
  //	cout << ss << "  ss\n" << s << "  s\n";
  //	cout << k << "k\n ";
  if (k > 0) {
    int sum = 0;
    ans = nn - 1;
    int now1 = 0;
    while (k > 0 && ss[now1] == s[now1])
      k--, ans--, now1++;
    int now2 = nn - 1;
    while (k > 0 && ss[now2] == s[now2])
      k--, ans--, now2--;
    if (k == 0) {
      cout << ans;
      return 0;
    }
    vector<pair<int, int>> res;
    for (int i = now1 + 1; i < now2 + 1; i++) {
      if (ss[i] == s[i] && ss[i - 1] == s[i - 1])
        sum++;
      else if (ss[i - 1] == s[i - 1]) {
        res.push_back({sum, i - 1});
        sum = 1;
      } else {
        sum = 0;
      }
    }
    sort(res.begin(), res.end());
    for (int i = res.size() - 1; i >= 0; i--) {
      if (k > res[i].first) {
        ans -= (res[i].first + 1);
        k -= res[i].first;
      } else {
        ans -= (k + 1);
        k = 0;
        break;
      }
    }
  }
  cout << ans;

  return 0;
}
/*
6 2
XYXXYX

5 4
XXYYY

12 10
XXYXYXXYYXXY

*/

// #include <bits/stdc++.h>
// using namespace std;
// #define REP(i, a, b) for (int i = (a); i <= (int)(b); i++)
// #define int long long
// const int kMaxN = 2e5 + 7;
// int n, k, cnt = 1e9, dis1[kMaxN], dis2[kMaxN], sd[kMaxN], nn;
// map<int, vector<int>> ton;
// bool f[kMaxN];
// string s, ss;

// signed main() {
//   ios::sync_with_stdio(0), cin.tie(0);
//   cin >> n >> k >> s;
//   if (n == 1)
//     return cout << "0", 0;
//   nn = n;
//   ss = s;
//   fill(f, f + kMaxN, 0);

//   // ---- 以下是你原有的 dis1/dis2 计算，我们保留不动 ----
//   for (int i = 0; i < n; i++) {
//     if (s[i] == 'X')
//       dis1[i] = cnt;
//     else {
//       dis1[i] = 1e9 + 100;
//       cnt = 0;
//     }
//     if (cnt != 1e9)
//       cnt++;
//   }
//   cnt = 1e9;
//   for (int i = n - 1; i >= 0; i--) {
//     if (s[i] == 'X')
//       dis2[i] = cnt;
//     else {
//       dis2[i] = 1e9 + 100;
//       cnt = 0;
//     }
//     if (cnt != 1e9)
//       cnt++;
//   }

//   // ---- 核心修改：不再使用 dis1+dis2 排序，而是直接收集被 Y 包围的 X 连续段
//   // ----
//   vector<int> gaps; // 存储每个中间X连续段的长度
//   int i = 0;
//   while (i < n && s[i] == 'X')
//     i++; // 跳过开头X
//   int cur = 0;
//   for (; i < n; i++) {
//     if (s[i] == 'X')
//       cur++;
//     else {
//       if (cur > 0) {
//         gaps.push_back(cur);
//         cur = 0;
//       }
//     }
//   }
//   // 结尾的X不加入gaps

//   // 统计X总数并判断是否可以全部转换
//   int x_cnt = 0;
//   for (char c : s)
//     if (c == 'X')
//       x_cnt++;
//   if (x_cnt <= k) {
//     cout << n << '\n';
//     return 0;
//   }

//   // 贪心：优先填补短的空隙
//   sort(gaps.begin(), gaps.end());
//   int used = 0;
//   int y_cnt = n - x_cnt; // 当前Y的个数
//   for (int gap : gaps) {
//     if (used + gap <= k) {
//       used += gap;
//       y_cnt += gap + 1; // 连接两段，净增加 gap+1 个 Y
//     } else {
//       break;
//     }
//   }

//   // 处理首尾的X
//   int left_x = 0, right_x = 0;
//   while (left_x < n && s[left_x] == 'X')
//     left_x++;
//   while (right_x < n && s[n - 1 - right_x] == 'X')
//     right_x++;
//   int boundary_x = left_x + right_x;
//   int remain = k - used;
//   y_cnt += min(remain, boundary_x);

//   cout << min(n, y_cnt) << '\n';

//   // 我们不再使用下面原来的后续处理代码，直接返回
//   return 0;
// }