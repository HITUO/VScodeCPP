#include <bits/stdc++.h>

using namespace std;

#define int long long

using LL = long long;
using VI = vector<int>;

const int kMaxN = 1e2 + 7;

int n, k, g[kMaxN][kMaxN], num[kMaxN];
VI ans;

void dfs(int k, int l, int sum) {
  if (k == n) {
    ans.push_back(sum + g[k][l]);
    return;
  }
  if (k > n) {
    ans.push_back(sum);
    return;
  }
  for (int i = 1; i <= num[k + 1]; i++) {
    dfs(k + 1, i, sum + g[k][l]);
  }
}

signed main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> num[i];
    for (int j = 1; j <= num[i]; j++) {
      cin >> g[i][j];
    }
  }
  for (int i = 1; i <= num[1]; i++) {
    dfs(1, i, 0);
  }
  sort(ans.begin(), ans.end());
  for (int i = 0; i < k; i++) {
    cout << ans[i] << " ";
  }
  return 0;
}