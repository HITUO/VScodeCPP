#include <bits/stdc++.h>

using namespace std;
map<int, vector<pair<int, int>>> rc;
int n, m;
long long ans = 0;
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int col;
      cin >> col;
      // 投入map中
      if (rc.find(col) != rc.end()) {
        rc[col].push_back(make_pair(i, j));
      } else {
        vector<pair<int, int>> tmp;
        tmp.push_back(make_pair(i, j));
        rc[col] = tmp;
      }
    }
  }
  for (auto p = rc.begin(); p != rc.end(); p++) {
    vector<pair<int, int>> points = p->second;
    vector<int> x_pos;
    vector<int> y_pos;
    vector<long long> sum_x;
    vector<long long> sum_y;
    for (int i = 0; i < points.size(); i++) {
      x_pos.push_back(points[i].first);
      y_pos.push_back(points[i].second);
    }
    // 排序
    sort(x_pos.begin(), x_pos.end());
    sort(y_pos.begin(), y_pos.end());
    // 前缀和计算
    for (int i = 0; i < points.size(); i++) {
      if (i == 0) {
        sum_x.push_back(x_pos[i]);
        sum_y.push_back(y_pos[i]);
      } else {
        sum_x.push_back(sum_x[i - 1] + x_pos[i]);
        sum_y.push_back(sum_y[i - 1] + y_pos[i]);
      }
    }
    for (int i = 1; i < points.size(); i++) {
      // 统计答案
      ans += (long long)(i)*x_pos[i] - sum_x[i - 1];
      ans += (long long)(i)*y_pos[i] - sum_y[i - 1];
    }
  }
  cout << ans << endl;
}

// T2
// #include <bits/stdc++.h>
// #define ll long long
//     using namespace std;
// const int N = 2e5 + 5, M = 4e5 + 5;
// int n, m, Q, head[N], tot;
// ll dis[N], vis[N];
// struct edge {
//   int v, nxt;
//   ll w;
// } eg[2 * M];
// void add(int u, int v, int w) {
//   eg[++tot].v = v;
//   eg[tot].w = w;
//   eg[tot].nxt = head[u];
//   head[u] = tot;
// }
// priority_queue<pair<ll, int>> q;
// int main() {
//   cin.tie(0)->ios::sync_with_stdio(0);
//   cin >> n >> m >> Q;
//   for (int i = 1, x; i <= n; i++) {
//     cin >> x;
//     if (x)
//       dis[i] = 1e18, q.push({1e18, i});
//   }
//   for (int i = 1, u, v, w; i <= m; i++) {
//     cin >> u >> v >> w;
//     add(u, v, w);
//     add(v, u, w);
//   }
//   while (q.size()) {
//     int u = q.top().second;
//     q.pop();
//     if (vis[u])
//       continue;
//     vis[u] = 1;
//     for (int i = head[u]; i; i = eg[i].nxt) {
//       int v = eg[i].v;
//       ll w = eg[i].w;
//       if (dis[v] >= dis[u])
//         continue;
//       dis[v] = min(dis[u], dis[v] + w);
//       q.push({dis[v], v});
//     }
//   }
//   while (Q--) {
//     int s;
//     ll k;
//     cin >> s >> k;
//     cout << (dis[s] < k ? "NO\n" : "YES\n");
//   }
//   return 0;
// }
// /*
// 2 0 2
// 1 0
// 1 1
// 2 1
// */

// T3

// #define N 18
//     int n,
//     a[N][N], e[N][N], bt[1 << N];
// char ch[N + 5];
// LL f[N][1 << N], g[1 << N];

// int main() {
//   read(n);
//   rep(i, 0, n - 1) {
//     rep(j, 0, n - 1) read(a[i][j]), a[i][j]--;
//     rep(j, 0, n - 1) {
//       e[i][a[i][j]] = 1;
//       if (a[i][j] == i)
//         break;
//     }
//   }
//   int w = (1 << n) - 1;
//   bt[0] = ~0;
//   rp(i, w) bt[i] = bt[i >> 1] + 1;
//   g[0] = 1;
//   rep(s, 0, w) {
//     int k = bt[s];
//     rep(i, 0, k) {
//       if (e[i][k])
//         g[s] += f[i][s];
//       rep(j, 0, k) if (!((s >> j) & 1) && e[i][j]) f[j][s | (1 << j)] +=
//           f[i][s];
//     }
//     rep(i, k + 1, n - 1) f[i][s | (1 << i)] += g[s];
//   }
//   int T;
//   read(T);
//   while (T--) {
//     scanf("%s", ch);
//     int s = 0;
//     rep(i, 0, n - 1) if (ch[i] == 'H') s |= 1 << i;
//     printf("%lld\n", g[s] * g[w ^ s]);
//   }
//   return 0;
// }

// T4
// #include <bits/stdc++.h>
// #define For(i, a, b) for (register int i = (a); i <= (b); ++i)
// #define Rep(i, a, b) for (register int i = (a); i >= (b); --i)
//     using namespace std;
// inline int read() {
//   char c = getchar();
//   int x = 0;
//   bool f = 0;
//   for (; !isdigit(c); c = getchar())
//     f ^= !(c ^ 45);
//   for (; isdigit(c); c = getchar())
//     x = (x << 1) + (x << 3) + (c ^ 48);
//   if (f)
//     x = -x;
//   return x;
// }
// #define maxn 200005
// int n, m, res;
// struct edge {
//   int to, nxt;
// } e[maxn << 1];
// int tot, head[maxn];
// inline void adde(int u, int v) {
//   e[++tot] = (edge){v, head[u]};
//   head[u] = tot;
// }
// #define inf 0x3f3f3f3f
// int a[maxn], f[maxn][3], g[maxn][3];
// // f[i][1/2] : u为1/2的最大儿子链
// // g[i][1/2] : u为1/2的答案
// void dfs(int u, int pa) {
//   int c = a[u];
//   if (c)
//     f[u][c ^ 3] = g[u][c ^ 3] = inf, f[u][c] = 0, g[u][c] = -inf;
//   else
//     f[u][1] = f[u][2] = 0, g[u][1] = g[u][2] = -inf;
//   for (int i = head[u]; i; i = e[i].nxt) {
//     int v = e[i].to;
//     if (v == pa)
//       continue;
//     dfs(v, u);
//     For(j, 1, 2) {
//       if (c + j == 3)
//         continue;
//       int tf = inf, tg = inf;
//       For(k, 1, 2) {
//         if (f[v][k] == inf)
//           continue;
//         tf = min(tf, f[v][k] + (j != k));
//         tg = min(tg, f[u][j] + f[v][k] + (j != k));
//       }
//       f[u][j] = max(f[u][j], tf);
//       g[u][j] = max(g[u][j], tg);
//     }
//   }
//   res = max(res, min(g[u][1], g[u][2]));
// }
// void work() {
//   n = read();
//   tot = 1;
//   For(i, 1, n) head[i] = 0, a[i] = read();
//   For(i, 2, n) {
//     int u = read(), v = read();
//     adde(u, v), adde(v, u);
//   }
//   res = 0;
//   dfs(1, 0);
//   printf("%d\n", (res + 1) / 2 + 1);
// }

// signed main() {
//   int T = read();
//   while (T--)
//     work();
//   return 0;
// }