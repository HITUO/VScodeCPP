#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, vis[10];
string s;
vector<int> a;
bool isp[10000001];
int zimu[26], flag = 0;
void dfs(int x, int num) {
  if (x == s.size()) {
    // cout<<num<<endl;
    if (!isp[num]) {
      flag = 1;
      cout << num;
      exit(0);
    }
    return;
  }
  if (zimu[s[x] - 'a'] >= 0) {
    dfs(x + 1, num + zimu[s[x] - 'a'] * pow(10, (s.size() - x - 1)));
  } else {
    for (int i = (x == 0 ? 1 : 0); i <= 9; i++) {
      if (vis[i])
        continue;
      vis[i] = 1;
      zimu[s[x] - 'a'] = i;
      dfs(x + 1, num + i * pow(10, (s.size() - x - 1)));
      vis[i] = 0;
      zimu[s[x] - 'a'] = -1;
    }
  }
}
signed main() {
  isp[1] = 1;
  //	for(int i=2;i<=1000000;i++)cout<<isp[i]<<" ";
  cin >> s;
  for (int i = 0; i < 26; i++) {
    zimu[i] = -1;
  }
  for (int i = 2; i <= 10000000; i++) {
    if (!isp[i]) {
      a.push_back(i);
      //		cout<<i<<endl;
    }
    for (auto j : a) {
      if (j * i > 10000000)
        break;
      isp[j * i] = 1;
      if (i % j == 0)
        break;
    }
  }
  //	cout<<a.size();
  dfs(0, 0);
  if (!flag) {
    cout << -1;
  }
}