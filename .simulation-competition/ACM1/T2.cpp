#include <bits/stdc++.h>
using namespace std;
const int N = 200005; // 数据范围
int n, k;             // n 代表字符串长度，k 代表翻转次数
string s;             // s 为输入的字符串
int cntX;             // 统计输入的字符串中 X 的个数
int ans;              // 记录答案的变量，初值为 0
vector<int> dis;      // 两个相邻 Y 之间 X 个数的序列
int main() {
  cin >> n >> k >> s;          // 读入 n, k, s
  for (int i = 0; s[i]; i++) { // 遍历整个字符串
    if (s[i] == 'X')
      cntX++; // 统计 X 的个数
  }
  if (cntX == 0) {                     // 特判 1
    printf("%d\n", max(n - k - 1, 0)); // 显而易见的答案
    return 0;                          // 直接退出程序
  }
  if (cntX == n) {                 // 特判 2
    printf("%d\n", max(k - 1, 0)); // 显而易见的答案
    return 0;                      // 直接退出程序
  }
  if (cntX < k) { // 翻转整个字符串，n - k to k
    k = n - k;    // 翻转次数也要翻转
    for (int i = 0; s[i]; i++) {
      s[i] = 'X' + 'Y' - s[i]; // 翻转 s[i]
    }
  }
  int lst = -1; // 表示上一个 Y 的位置
  for (int i = 0; s[i]; i++) {
    if (s[i] == 'Y') {
      if (lst != -1) {              // 特判第一个 Y
        dis.push_back(i - lst - 1); // 两个相邻的 Y 之间 X 的数量
      }
      lst = i; // 更新上一个 Y 的位置
    }
  }
  sort(dis.begin(), dis.end()); // 从小到大排序
  for (int i : dis) {           // 遍历序列
    if (k >= i) {
      k -= i;       // 使用 i 次翻转
      ans += 1 + i; // 对答案造成 i + 1 的贡献
    }
  }
  ans += k;            // 使用剩下的 k 次翻转，对答案造成 k 的贡献
  printf("%d\n", ans); // 输出答案
  return 0;
}