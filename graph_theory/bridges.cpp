vi grafo[N], tin(N), low(N), vis(N); 
set<pair<int,int>> s; 
int timer, n, m, x;
void bridge(int i, int j) {
    if (i>j) swap(i, j); 
    s.insert({i, j});
}
int is_bridge(int i,int j) {
    if (i>j) swap(i, j); 
    return s.count({i,j});
}
void dfs(int v, int p = -1) {
    vis[v] = true;
    tin[v] = low[v] = timer++;
    bool parent_skipped = false;
    for (int to : grafo[v]) {
        if (to == p && !parent_skipped) {
            parent_skipped = true;
            continue;
        }
        if (vis[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v])
                bridge(v, to);
        }
    }
}
void find_bridges() {
    timer = 0;
    for (int i = 1; i <= n; ++i) {
        if (!vis[i])
            dfs(i);
    }
}