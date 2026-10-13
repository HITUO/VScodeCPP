#include <bits/stdc++.h>

using namespace std;
using LL = long long;

const int NN = 1e6;
const LL INF = 2e18;

int N, M, D;
LL maxt[NN], addv[NN], minf[NN], maxf[NN];

void set_v(int o, int L, int R, int x, int v) {
  if (L == R)
    return minf[o] = maxf[o] = v + addv[o], void();
  int m = (L + R) / 2, lc = 2 * o, rc = 2 * o + 1;
  if (x <= m)
    set_v(lc, L, m, x, v);
  else
    minf[lc] += D, maxf[lc] += D, addv[lc] += D, set_v(rc, m + 1, R, x, v);
  minf[o] = addv[o] + min(minf[lc], minf[rc]);
  maxf[o] = addv[o] + max(maxf[lc], maxf[rc]);
  maxt[o] = max({maxt[lc], maxt[rc], maxf[lc] - minf[rc]});
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> N >> M >> D;
  fill_n(minf, NN, INF);
  fill_n(maxf, NN, -INF);
  int n2 = N + M;
  vector<int> a(n2 + 1), id(n2 + 1);
  vector<array<int, 2>> s(n2 + 1);
  for (int i = 1; i <= n2; i++)
    cin >> a[i], s[i] = {a[i], i};
  sort(begin(s) + 1, end(s));
  for (int i = 1; i <= n2; i++)
    id[s[i][1]] = i;
  for (int i = 1; i <= n2; i++) {
    set_v(1, 1, n2, id[i], a[i]);
    if (i > N)
      cout << maxt[1] / 2 << (maxt[1] & 1 ? ".5 " : " ");
  }
  return 0;
}