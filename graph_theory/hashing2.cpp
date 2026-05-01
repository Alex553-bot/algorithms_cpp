//Permite hashear árboles para comparar su estructura
//Agregar Random Integer para ll
map<int, int> table;
int get(int x) {
    if (table.count(x)) return table[x];
    return table[x] = rand(0, 1e18);
}
int hashes[N], sum[N];
void dfs(int u, int p) {
  sum[u] = 0;
  for (auto &v : g[u]) {
    if (v == p) continue;
    dfs(v, u);
    sum[u] += hashes[v];
  }
  hashes[u] = get(sum[u]);
}