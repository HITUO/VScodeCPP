#include <bits/stdc++.h>
using namespace std;
// ==================== 1. 快速幂 ====================
// 功能：计算 (a^b) % mod，时间复杂度 O(log b)
long long qpow(long long a, long long b, long long mod) {
  long long res = 1; // 结果初始化为1
  while (b > 0) {    // 指数大于0时循环
    if (b & 1)
      res = res * a % mod; // 当前二进制位为1，乘上a
    a = a * a % mod;       // a自乘（平方）
    b >>= 1;               // 指数右移一位
  }
  return res;
}
// ==================== 2. 一维前缀和 ====================
// 功能：构建前缀和数组，pre[i] = a[1] + ... + a[i]，查询区间和 O(1)
vector<int> buildPrefix(const vector<int> &a) {
  int n = a.size() - 1;      // 原数组下标从1开始
  vector<int> pre(n + 1, 0); // pre[i]表示前i个元素的和
  for (int i = 1; i <= n; i++)
    pre[i] = pre[i - 1] + a[i];
  return pre;
}
// 查询区间 [l, r] 的和：pre[r] - pre[l - 1]
// ==================== 3. 二维前缀和 ====================
// 功能：构建二维前缀和，sum[i][j] = 从(1,1)到(i,j)的子矩阵和，查询 O(1)
vector<vector<int>> buildPrefix2D(const vector<vector<int>> &a) {
  int n = a.size() - 1, m = a[0].size() - 1;
  vector<vector<int>> sum(n + 1, vector<int>(m + 1, 0));
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      sum[i][j] = a[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
  return sum;
}
// 查询子矩阵 (x1,y1)-(x2,y2)：sum[x2][y2] - sum[x1-1][y2] - sum[x2][y1-1] +
// sum[x1-1][y1-1]
// ==================== 4. 一维差分 ====================
// 功能：对区间 [l, r] 统一加 v，最后做前缀和还原，O(1)修改
vector<int> diff;
void initDiff(int n) { diff.assign(n + 2, 0); }
void addRange(int l, int r, int v) {
  diff[l] += v;
  diff[r + 1] -= v;
}
void restore1D(int n) {
  for (int i = 1; i <= n; i++)
    diff[i] += diff[i - 1];
}
// ==================== 5. 二维差分 ====================
// 功能：对子矩阵 (x1,y1)-(x2,y2) 统一加 v，最后做二维前缀和还原
vector<vector<int>> diff2D;
void initDiff2D(int n, int m) { diff2D.assign(n + 2, vector<int>(m + 2, 0)); }
void addSubMatrix(int x1, int y1, int x2, int y2, int v) {
  diff2D[x1][y1] += v;
  diff2D[x2 + 1][y1] -= v;
  diff2D[x1][y2 + 1] -= v;
  diff2D[x2 + 1][y2 + 1] += v;
}
void restore2D(int n, int m) {
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      diff2D[i][j] +=
          diff2D[i - 1][j] + diff2D[i][j - 1] - diff2D[i - 1][j - 1];
}
// ==================== 6. ST表（区间最值查询） ====================
// 功能：预处理 O(n log n)，查询区间最值 O(1)，不支持修改
struct SparseTable {
  int n, LOG;             // n为数组长度，LOG为log2(n)+1
  vector<vector<int>> st; // st[k][i]表示从i开始长度2^k的区间最值
  vector<int> lg;         // lg[i]表示log2(i)向下取整
  SparseTable() {}
  SparseTable(const vector<int> &a) { build(a); }
  void build(const vector<int> &a) {
    n = a.size();
    if (n == 0)
      return;
    LOG = 1;
    while ((1 << LOG) <= n)
      LOG++;
    st.assign(LOG, vector<int>(n));
    lg.assign(n + 1, 0);
    for (int i = 2; i <= n; i++)
      lg[i] = lg[i / 2] + 1;
    for (int i = 0; i < n; i++)
      st[0][i] = a[i];
    for (int k = 1; k < LOG; k++)
      for (int i = 0; i + (1 << k) <= n; i++)
        st[k][i] = max(st[k - 1][i], st[k - 1][i + (1 << (k - 1))]);
  }
  int queryMax(int l, int r) { // 查询 [l,r] 最大值，0-based
    if (l > r)
      swap(l, r);
    int len = r - l + 1, k = lg[len];
    return max(st[k][l], st[k][r - (1 << k) + 1]);
  }
  int queryMin(int l, int r) { // 查询 [l,r] 最小值，0-based
    if (l > r)
      swap(l, r);
    int len = r - l + 1, k = lg[len];
    return min(st[k][l], st[k][r - (1 << k) + 1]);
  }
};
// ==================== 7. 并查集 ====================
// 功能：集合合并与连通性查询，find O(α(n))，unite O(α(n))
struct DSU {
  vector<int> p, r; // p父节点，r树高（秩）
  DSU(int n) {
    p.resize(n + 1);
    r.assign(n + 1, 0);
    for (int i = 1; i <= n; i++)
      p[i] = i;
  }
  int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); } // 路径压缩
  void unite(int x, int y) { // 合并x和y所在集合
    int rx = find(x), ry = find(y);
    if (rx == ry)
      return;
    if (r[rx] < r[ry])
      swap(rx, ry);
    p[ry] = rx;
    if (r[rx] == r[ry])
      r[rx]++;
  }
  bool same(int x, int y) { return find(x) == find(y); } // 判断是否在同一集合
};
// ==================== 8. BFS（网格最短路） ====================
// 功能：从(sx,sy)到(tx,ty)的最短步数，4方向移动，0可走1不可走
int bfsGrid(const vector<vector<int>> &grid, int sx, int sy, int tx, int ty) {
  int n = grid.size(), m = grid[0].size();
  int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  vector<vector<int>> dist(n, vector<int>(m, -1));
  queue<pair<int, int>> q;
  dist[sx][sy] = 0;
  q.push({sx, sy});
  while (!q.empty()) {
    pair<int, int> p = q.front();
    q.pop();
    int x = p.first, y = p.second;
    if (x == tx && y == ty)
      return dist[x][y];
    for (int i = 0; i < 4; i++) {
      int nx = x + dirs[i][0], ny = y + dirs[i][1];
      if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 0 &&
          dist[nx][ny] == -1) {
        dist[nx][ny] = dist[x][y] + 1;
        q.push({nx, ny});
      }
    }
  }
  return -1; // 不可达
}
// ==================== 9. 01背包 ====================
// 功能：每个物品最多选一次，容量W下最大总价值，时间复杂度 O(nW)
int knap01(const vector<int> &w, const vector<int> &v, int W) {
  int n = w.size() - 1;     // 物品数量，下标从1开始
  vector<int> dp(W + 1, 0); // dp[j]容量j时的最大价值
  for (int i = 1; i <= n; i++)
    for (int j = W; j >= w[i]; j--) // 倒序，保证每个物品只选一次
      dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
  return dp[W];
}
// ==================== 10. 最长上升子序列 (LIS) ====================
// 功能：计算最长严格上升子序列长度，时间复杂度 O(n log n)
int LIS(const vector<int> &nums) {
  vector<int> tails; // tails[k]表示长度k+1的LIS最小末尾
  for (int x : nums) {
    auto it = lower_bound(tails.begin(), tails.end(), x);
    if (it == tails.end())
      tails.push_back(x);
    else
      *it = x;
  }
  return tails.size();
}
// ==================== 11. 快速读入 ====================
// 功能：快速读入一个整数（支持负数），比cin快很多
inline int read() {
  int x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-')
      f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + (c - '0');
    c = getchar();
  }
  return x * f;
}
// ==================== 12. 欧拉筛（线性筛素数） ====================
// 功能：返回 [2, n] 内所有素数，每个合数只被最小质因子筛一次，O(n)
vector<int> getPrimes(int n) {
  vector<int> primes;
  vector<bool> isComp(n + 1, false);
  if (n >= 0)
    isComp[0] = true;
  if (n >= 1)
    isComp[1] = true;
  for (int i = 2; i <= n; i++) {
    if (!isComp[i])
      primes.push_back(i);
    for (int p : primes) {
      if (1LL * i * p > n)
        break;
      isComp[i * p] = true;
      if (i % p == 0)
        break; // 保证每个合数只被最小质因子筛掉
    }
  }
  return primes;
}
// ==================== 13. 最大公约数 (GCD) ====================
// 功能：欧几里得算法求最大公约数，时间复杂度 O(log min(a,b))
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
// 最小公倍数：a / gcd(a,b) * b（注意溢出用 long long）
// ==================== 14. 拓扑排序（有向无环图） ====================
// 功能：返回拓扑序，若图有环返回空，时间复杂度 O(n+m)
vector<int> topoSort(int n, const vector<vector<int>> &adj) {
  vector<int> indeg(n + 1, 0);
  for (int u = 1; u <= n; u++)
    for (int v : adj[u])
      indeg[v]++;
  queue<int> q;
  for (int i = 1; i <= n; i++)
    if (indeg[i] == 0)
      q.push(i);
  vector<int> order;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    order.push_back(u);
    for (int v : adj[u])
      if (--indeg[v] == 0)
        q.push(v);
  }
  return order.size() == (size_t)n ? order : vector<int>();
}
// ==================== 15. Dijkstra（单源最短路） ====================
// 功能：非负权图单源最短路，O(m log n)，返回dist数组
vector<int> dijkstra(int n, const vector<vector<pair<int, int>>> &adj,
                     int src) {
  const int INF = 1e9;
  vector<int> dist(n + 1, INF);
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  dist[src] = 0;
  pq.push({0, src});
  while (!pq.empty()) {
    pair<int, int> p = pq.top();
    pq.pop();
    int d = p.first, u = p.second;
    if (d != dist[u])
      continue;
    for (int i = 0; i < (int)adj[u].size(); i++) {
      int v = adj[u][i].first, w = adj[u][i].second;
      if (dist[v] > dist[u] + w) {
        dist[v] = dist[u] + w;
        pq.push({dist[v], v});
      }
    }
  }
  return dist;
}
// ==================== 16. SPFA（队列优化Bellman-Ford） ====================
// 功能：支持负权边单源最短路，可检测负环（返回空），一般O(km)
vector<int> spfa(int n, const vector<vector<pair<int, int>>> &adj, int src) {
  const int INF = 1e9;
  vector<int> dist(n + 1, INF);
  vector<bool> inq(n + 1, false);
  vector<int> cnt(n + 1, 0);
  queue<int> q;
  dist[src] = 0;
  q.push(src);
  inq[src] = true;
  cnt[src]++;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    inq[u] = false;
    for (int i = 0; i < (int)adj[u].size(); i++) {
      int v = adj[u][i].first, w = adj[u][i].second;
      if (dist[v] > dist[u] + w) {
        dist[v] = dist[u] + w;
        if (!inq[v]) {
          q.push(v);
          inq[v] = true;
          cnt[v]++;
          if (cnt[v] >= n)
            return vector<int>(); // 有负环
        }
      }
    }
  }
  return dist;
}
// ==================== 17. 单调栈 ====================
// 功能：找每个元素右边第一个更大的数，不存在为-1，O(n)
vector<int> nextGreater(vector<int> &nums) {
  int n = nums.size();
  vector<int> ans(n, -1);
  stack<int> stk; // 栈存下标，维护单调递减
  for (int i = 0; i < n; i++) {
    while (!stk.empty() && nums[stk.top()] < nums[i]) {
      ans[stk.top()] = nums[i];
      stk.pop();
    }
    stk.push(i);
  }
  return ans;
}
// ==================== 18. 单调队列（滑动窗口最大值） ====================
// 功能：求每个长度为k的窗口最大值，O(n)
vector<int> slidingWindowMax(vector<int> &nums, int k) {
  vector<int> ans;
  deque<int> dq; // 存下标，维护单调递减
  for (int i = 0; i < (int)nums.size(); i++) {
    while (!dq.empty() && dq.front() <= i - k)
      dq.pop_front(); // 移除过期
    while (!dq.empty() && nums[dq.back()] <= nums[i])
      dq.pop_back(); // 移除比当前小的
    dq.push_back(i);
    if (i >= k - 1)
      ans.push_back(nums[dq.front()]);
  }
  return ans;
}
// ==================== 19. n进制转m进制 ====================
// 功能：将num从fromBase进制转为toBase进制，支持2~36进制
string convertBase(string num, int fromBase, int toBase) {
  if (num.empty())
    return "";
  long long decimal = 0;
  for (char c : num) {
    int digit = (c >= '0' && c <= '9') ? c - '0' : c - 'A' + 10;
    decimal = decimal * fromBase + digit;
  }
  if (decimal == 0)
    return "0";
  string res;
  while (decimal > 0) {
    int rem = decimal % toBase;
    res = (char)(rem < 10 ? rem + '0' : rem - 10 + 'A') + res;
    decimal /= toBase;
  }
  return res;
}
// ==================== 20. Manacher（马拉车） ====================
// 功能：求最长回文子串，O(n)，返回原串中的最长回文子串
string manacher(string s) {
  if (s.empty())
    return "";
  string t = "#"; // 插入分隔符，统一奇偶
  for (char c : s) {
    t += c;
    t += '#';
  }
  int n = t.size();
  vector<int> d(n, 0); // d[i]以i为中心的回文半径（含中心）
  int l = 0, r = -1, center = 0;
  for (int i = 0; i < n; i++) {
    int k = (i > r) ? 1 : min(d[l + r - i], r - i + 1);
    while (i - k >= 0 && i + k < n && t[i - k] == t[i + k])
      k++;
    d[i] = k--;
    if (i + k > r) {
      l = i - k;
      r = i + k;
    }
    if (d[i] > d[center])
      center = i;
  }
  return s.substr((center - d[center] + 1) / 2, d[center] - 1);
}
// ==================== 21. KMP（字符串匹配） ====================
// 功能：返回模式串p在文本串s中首次出现的位置，0-based，找不到返回-1
vector<int> getNext(const string &p) {
  int m = p.size();
  vector<int> nxt(m, 0);
  for (int i = 1, j = 0; i < m; i++) {
    while (j > 0 && p[i] != p[j])
      j = nxt[j - 1];
    if (p[i] == p[j])
      j++;
    nxt[i] = j;
  }
  return nxt;
}
int kmp(const string &s, const string &p) {
  int n = s.size(), m = p.size();
  if (m == 0)
    return 0;
  vector<int> nxt = getNext(p);
  for (int i = 0, j = 0; i < n; i++) {
    while (j > 0 && s[i] != p[j])
      j = nxt[j - 1];
    if (s[i] == p[j])
      j++;
    if (j == m)
      return i - m + 1;
  }
  return -1;
}
// ==================== 22. 离散化 ====================
// 功能：将数组压缩为1~k的连续值，保持大小关系不变
vector<int> discretize(vector<int> a) {
  vector<int> vals = a;
  sort(vals.begin(), vals.end());
  vals.erase(unique(vals.begin(), vals.end()), vals.end());
  for (int &x : a)
    x = lower_bound(vals.begin(), vals.end(), x) - vals.begin() + 1;
  return a;
}
// ==================== 主函数 - STL操作演示 ====================
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  // ========== 1. vector（动态数组） ==========
  // 功能：可变长数组，支持随机访问，尾部增删 O(1)
  vector<int> v = {5, 2, 8, 1, 9};
  v.push_back(3);              // 在末尾添加元素3
  v.pop_back();                // 删除末尾元素
  v.insert(v.begin() + 2, 7);  // 在位置2插入7（O(n)）
  v.erase(v.begin() + 1);      // 删除位置1的元素（O(n)）
  sort(v.begin(), v.end());    // 排序 [1,2,5,7,8,9]
  reverse(v.begin(), v.end()); // 反转 [9,8,7,5,2,1]
  // 常用函数：v.front()第一个，v.back()最后一个，v.empty()判空，v.size()长度，v.clear()清空

  // ========== 2. stack（栈，LIFO） ==========
  // 功能：后进先出容器，无遍历，顶部操作 O(1)
  stack<int> stk;
  stk.push(10); // 入栈
  stk.push(20);
  stk.top();   // 返回栈顶元素（不弹出）20
  stk.pop();   // 弹出栈顶
  stk.empty(); // 判空

  // ========== 3. queue（队列，FIFO） ==========
  // 功能：先进先出容器，无遍历，首尾操作 O(1)
  queue<int> q;
  q.push(10); // 入队
  q.push(20);
  q.front(); // 返回队首元素 10
  q.back();  // 返回队尾元素 20
  q.pop();   // 出队
  q.empty(); // 判空

  // ========== 4. deque（双端队列） ==========
  // 功能：支持两端高效增删，随机访问 O(1)
  deque<int> dq = {1, 2, 3};
  dq.push_front(0); // 队头插入0
  dq.push_back(4);  // 队尾插入4
  dq.pop_front();   // 删除队头
  dq.pop_back();    // 删除队尾
  dq.front();       // 队首元素
  dq.back();        // 队尾元素

  // ========== 5. priority_queue（优先队列/堆） ==========
  // 功能：默认大根堆（最大值在堆顶），插入/删除 O(log n)
  priority_queue<int> pq;
  pq.push(10);
  pq.push(30);
  pq.push(20);
  pq.top(); // 堆顶元素 30（最大值）
  pq.pop(); // 弹出堆顶
  // 小根堆：priority_queue<int, vector<int>, greater<int>> minHeap;
  priority_queue<int, vector<int>, greater<int>> minHeap;
  minHeap.push(10);
  minHeap.push(30);
  minHeap.push(20);
  minHeap.top(); // 堆顶元素 10（最小值）

  // ========== 6. pair（二元组） ==========
  // 功能：存储两个值，比较时先比first再比second
  pair<int, string> p = {1, "abc"};
  p.first;  // 第一个元素 1
  p.second; // 第二个元素 "abc"
  // 自动支持 > < == 比较

  // ========== 7. set（有序集合） ==========
  // 功能：自动去重且升序排列，增删查 O(log n)
  set<int> s = {3, 1, 2}; // s = {1,2,3}
  s.insert(4);            // 插入4
  s.erase(2);             // 删除2
  s.find(3);              // 查找3，返回迭代器，找不到返回 s.end()
  s.count(3);             // 判断3是否存在，存在返回1
  // unordered_set：哈希实现，O(1)增删查，但不排序

  // ========== 8. map（有序映射表） ==========
  // 功能：键值对存储，按key升序排列，增删查 O(log n)
  map<int, string> mp;
  mp[1] = "one"; // 插入/修改 key=1
  mp[2] = "two";
  mp.insert({3, "three"}); // 插入键值对
  mp[2];                   // 取值 "two"
  mp.erase(1);             // 删除key=1
  mp.find(2);              // 查找key=2，返回迭代器
  mp.count(3);             // 判断key=3是否存在
  // unordered_map：哈希实现，O(1)增删查，但不排序

  // ========== 9. 迭代器遍历 ==========
  // 功能：遍历容器中的元素
  for (int x : v)
    cout << x << " "; // 范围for（只读）
  for (auto it = v.begin(); it != v.end(); it++) {
    int x = *it;
  } // 迭代器
  for (auto &kv : mp) {
    cout << kv.first << "->" << kv.second;
  } // map遍历

  // ========== 10. 常用算法（<algorithm>） ==========
  // 功能：STL提供的通用算法函数
  vector<int> a = {3, 1, 4, 1, 5, 9, 2, 6};
  sort(a.begin(), a.end());    // 排序 O(n log n)，a = {1,1,2,3,4,5,6,9}
  reverse(a.begin(), a.end()); // 反转 O(n)，a = {9,6,5,4,3,2,1,1}
  int t = *max_element(a.begin(), a.end()); // 返回最大值的迭代器，*it = 9
  min_element(a.begin(), a.end());          // 返回最小值的迭代器，*it = 1
  accumulate(a.begin(), a.end(), 0);        // 求和（需 <numeric>），返回总和
  find(a.begin(), a.end(), 5); // 线性查找，返回迭代器，找不到返回 end()
  binary_search(a.begin(), a.end(), 5); // 二分查找，要求已排序，返回bool
  a.erase(unique(a.begin(), a.end()),
          a.end()); // 去重（先排序），a = {1,2,3,4,5,6,9}

  // ========== 11. 算法模板测试 ==========
  cout << qpow(2, 10, 1000000007) << endl; // 快速幂：2^10 % 1e9+7 = 1024
  DSU dsu(5);
  dsu.unite(1, 2);
  cout << dsu.same(1, 2) << endl; // 并查集：1和2在同一集合，输出1
  vector<int> arr = {3, 1, 4, 1, 5, 9, 2, 6};
  SparseTable st(arr);
  cout << st.queryMax(1, 4) << endl; // ST表最大值：max(1,4,1,5) = 5
  cout << st.queryMin(2, 5) << endl; // ST表最小值：min(4,1,5,9) = 1
  cout << LIS({10, 9, 2, 5, 3, 7, 101, 18}) << endl; // LIS长度 = 4
  vector<int> w = {0, 2, 3, 4, 5}, val = {0, 3, 4, 5, 6};
  cout << knap01(w, val, 8) << endl; // 01背包最大价值 = 10

  return 0;
}

/*

#include <bits/stdc++.h>

using namespace std;

#define int long long

const int kM = 1e5 + 7;

int a[kM], w[kM * 4], lzy[kM * 4];

void pushup(const int u) { w[u] = w[u * 2] + w[u * 2 + 1]; }

void build(const int u, int L, int R) {
  if (L == R) {
    w[u] = a[L];
    return;
  }
  int M = (L + R) >> 1;
  build(u * 2, L, M);
  build(u * 2 + 1, M + 1, R);
  pushup(u);
}

bool ir(int L, int R, int l, int r) { return (l <= L) && (R <= r); }

bool oor(int L, int R, int l, int r) { return (L > r) || (R < l); }

void maketag(int u, int len, int x) {
  lzy[u] += x;
  w[u] += len * x;
}

void pushdown(int u, int L, int R) {
  int M = (L + R) >> 1;
  maketag(u * 2, M - L + 1, lzy[u]);
  maketag(u * 2 + 1, R - M, lzy[u]);
  lzy[u] = 0;
}

int query(int u, int L, int R, int l, int r) {
  if (ir(L, R, l, r)) {
    return w[u];
  } else if (!oor(L, R, l, r)) {
    int M = (L + R) >> 1;
    pushdown(u, L, R);
    return query(u * 2, L, M, l, r) + query(u * 2 + 1, M + 1, R, l, r);
  } else {
    return 0;
  }
}

void update(int u, int L, int R, int l, int r, int x) {
  if (ir(L, R, l, r))
    maketag(u, R - L + 1, x);
  else if (!oor(L, R, l, r)) {
    int M = (L + R) >> 1;
    pushdown(u, L, R);
    update(u * 2, L, M, l, r, x);
    update(u * 2 + 1, M + 1, R, l, r, x);
    pushup(u);
  }
}

signed main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  build(1, 1, n);
  for (int i = 1, op, x, y, k; i <= m; i++) {
    cin >> op;
    if (op == 1) {
      cin >> x >> y >> k;
      update(1, 1, n, x, y, k);
    } else {
      cin >> x >> y;
      cout << query(1, 1, n, x, y) << "\n";
    }
  }
  return 0;
}*/