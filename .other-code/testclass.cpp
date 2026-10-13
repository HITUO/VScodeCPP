#include <bits/stdc++.h>

using namespace std;

#define int long long

using LL = long long;
using VI = vector<int>;

const int kMaxN = 2e5 + 7;

class Test {
private:
  int a, b, c;

public:
  void change(char s, int x) {
    switch (s) {
    case 'a':
      a = x;
      break;
    case 'b':
      b = x;
      break;
    case 'c':
      c = x;
      break;
    default:
      cout << "Error!\n";
      break;
    }
  }
  [[nodiscard]] int get_grade() {
    return (int)round(a * 0.5 + b * 0.4 + c * 0.1);
  }
};

signed main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  Test g;
  g.change('a', 10);
  g.change('b', 10);
  g.change('c', 10);
  g.change('d', 10);
  cout << g.get_grade();
  return 0;
}