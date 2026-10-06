#include <cstdio>
#include <cstring>
#define re register
#if defined(__linux__)
#define getchar getchar_unlocked
#define putchar putchar_unlocked
#endif
typedef long long LL;
inline void read(int &x) {
  char c;
  bool f = false;
  while ((c = getchar()) < '0')
    if (c == '-')
      f = true;
  do
    x = (x << 1) + (x << 3) + (c ^ 48);
  while ((c = getchar()) > '-');
  if (f)
    x = ~x + 1;
}
inline int read() {
  int x = 0;
  char c;
  while ((c = getchar()) < '0')
    ;
  do
    x = (x << 1) + (x << 3) + (c ^ 48);
  while ((c = getchar()) > '-');
  return x;
}
inline LL max(LL a, LL b) { return a > b ? a : b; }
inline LL min(LL a, LL b) { return a < b ? a : b; }
inline void Max(LL &a, LL b) {
  if (a < b)
    a = b;
}
inline void Min(LL &a, LL b) {
  if (a > b)
    a = b;
}
const int N = 5e5 + 5;
int w[N], h[N], e[N << 1], ne[N << 1], idx;
inline void add(int a, int b) { ne[++idx] = h[a], e[h[a] = idx] = b; }
const LL INF = 0xc1c1c1c1c1c1c1c1;
LL sz[N], mx1[N], mxsn[N], mx2[N], mn1[N], mnsn[N], mn2[N], ans = INF;
void dfs(int u, int f) {
  sz[u] = w[u];
  for (int i = h[u], v; i; i = ne[i])
    if ((v = e[i]) != f) {
      dfs(v, u), sz[u] += sz[v];
      LL mx = max(mx1[v], sz[v]), mn = min(mn1[v], sz[v]);
      if (mx > mx1[u])
        mxsn[u] = v, mx2[u] = mx1[u], mx1[u] = mx;
      else if (mx > mx2[u])
        mx2[u] = mx;
      if (mn < mn1[u])
        mnsn[u] = v, mn2[u] = mn1[u], mn1[u] = mn;
      else if (mn < mn2[u])
        mn2[u] = mn;
    }
}
inline LL mid(LL a, LL b, LL c) {
  if (a <= b && b <= c || a >= b && b >= c)
    return b;
  if (b <= c && c <= a || b >= c && c >= a)
    return c;
  return a;
}
void solve(int u, int f, LL maxu, LL minu) {
  // maxu 和 minu 是 u 父方向（上方）子树的信息
  for (int i = h[u], v; i; i = ne[i])
    if ((v = e[i]) != f) {
      LL mxu = max(maxu, mxsn[u] != v ? mx1[u] : mx2[u]),
         mnu = min(minu, mnsn[u] != v ? mn1[u] : mn2[u]), szu = 1 [sz] - sz[v];
      // mxu 和 mnu 尝试用 v 的兄弟节点信息更新 \
			因为选择了 v 之后，v 的兄弟都会被归入 u 一侧的子树中
      // szu 是 u 一侧子树的权值

      // 以下两个判断均为防止某一侧子树无法划分
      if (u != 1 || ne[1 [h]]) // 防止 u 一侧
        Max(ans, mid(mxu, szu - mxu, sz[v])),
            Max(ans, mid(mnu, szu - mnu, sz[v]));
      if (mx1[v] != INF) // 防止 v 一侧
        Max(ans, mid(mx1[v], sz[v] - mx1[v], szu)),
            Max(ans, mid(mn1[v], sz[v] - mn1[v], szu));
      solve(v, u, max(mxu, szu), min(mnu, szu));
      // 类似地，u 一侧子树的信息也要传递
    }
}
int main() {

  freopen("young.in", "r", stdin);
  freopen("young.out", "w", stdout);

  int n;
  scanf("%d", &n);
  for (int i = 0; i != n; read(w[++i]))
    ;
  for (int i = 1; i != n; ++i) {
    int u = read(), v = read();
    add(u, v), add(v, u);
  }
  memset(mx1 + 1, 0xc1, n * sizeof(LL)), memset(mx2 + 1, 0xc1, n * sizeof(LL));
  memset(mn1 + 1, 0x3f, n * sizeof(LL)), memset(mn2 + 1, 0x3f, n * sizeof(LL));
  dfs(1, 0);
  solve(1, 0, INF, 0x3f3f3f3f3f3f3f3f);
  printf("%lld", ans);
  return 0;
}
