
queue<int> q;

void add(int u, int v, int w) {
  edge[++num_edge] = {u, v, head[u], w};
  head[u] = num_edge;