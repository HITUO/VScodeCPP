#include <bits/stdc++.h>

using namespace std;

#define int long long

using LL = long long;
using VI = vector<int>;

const int kMaxN = 1e2 + 7;

int n, k, g[kMaxN][kMaxN], num[kMaxN], cnt;
int suf_min[kMaxN];
priority_queue<int> pq;

void dfs(int k, int l, int sum) {
  if ((int)pq.size() == ::k && sum + g[k][l] + suf_min[k + 1] >= pq.top()) {
    return;
  }
  if (k == n) {
    pq.push(sum + g[k][l]);
    if ((int)pq.size() > ::k) {
      pq.pop();
    }
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
    sort(g[i] + 1, g[i] + num[i] + 1);
  }
  suf_min[n + 1] = 0;
  for (int i = n; i >= 1; i--) {
    suf_min[i] = suf_min[i + 1] + g[i][1];
  }
  for (int i = 1; i <= num[1]; i++) {
    dfs(1, i, 0);
  }
  VI ans;
  while (!pq.empty()) {
    ans.push_back(pq.top());
    pq.pop();
  }
  reverse(ans.begin(), ans.end());
  for (int i = 0; i < k && i < (int)ans.size(); i++) {
    if (i) {
      cout << " ";
    }
    cout << ans[i];
  }
  cout << "\n";
  return 0;
}