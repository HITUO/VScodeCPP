#include <iostream>
#include <queue>
#include <vector>

int main() {
  freopen("snack.in", "r", stdin);
  freopen("snack.out", "w", stdout);
  int n;
  std::cin >> n;

  std::vector<std::vector<int>> graph(n + 1);
  std::vector<int> degree(n + 1);

  for (int i = 1; i <= n; ++i) {
    int ci;
    std::cin >> ci;
    for (int j = 0; j < ci; ++j) {
      int ai;
      std::cin >> ai;
      graph[ai].push_back(i);
      ++degree[i];
    }
  }

  std::queue<int> q;
  for (int i = 1; i <= n; ++i) {
    if (degree[i] == 0) {
      q.push(i);
    }
  }

  std::vector<int> order;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    order.push_back(u);
    for (int v : graph[u]) {
      --degree[v];
      if (degree[v] == 0) {
        q.push(v);
      }
    }
  }

  if (order.size() != n) {
    std::cout << -1;
  } else {
    for (int i = 0; i < n; ++i) {
      std::cout << order[i] << " ";
    }
    std::cout << std::endl;
  }

  return 0;
}
