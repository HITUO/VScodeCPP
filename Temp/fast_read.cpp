#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using VI = vector<int>;

namespace FastIO {
const int SIZE = 1 << 16;

char buf[SIZE];
int idx = 0, len = 0;

inline int gc() {
  if (idx == len) {
    len = fread(buf, 1, SIZE, stdin);
    idx = 0;
    if (!len) {
      return EOF;
    }
  }
  return (unsigned char)buf[idx++];
}

template <typename T = long long> inline T read() {
  T x = 0;
  int f = 1;
  int ch = gc();

  while (ch < '0' || ch > '9') {
    if (ch == '-') {
      f = -1;
    }
    ch = gc();
  }

  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = gc();
  }

  return x * f;
}
} // namespace FastIO

using namespace FastIO;

#define int long long

const int kMaxN = 2e5 + 7;

signed main() {
  int a = read();
  cout << a + 1;
  return 0;
}