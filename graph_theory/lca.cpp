int n, q, timer = 0, l;
vi grafo[N+1], tin(N+1, 0), tout(N+1, 0);
vector<vi> dp;
void dfs(int i = 1, int p = 1) {
	tin[i] = timer++;
	dp[i][0] = p;
	for (int j = 1; j<=l; j++) 
		dp[i][j] = dp[dp[i][j-1]][j-1];
	
	for (auto &to: grafo[i]) 
		if (to!=p) dfs(to, i);
	tout[i] = timer++;
}
int is_ancestor(int i, int j) {
	return tin[i]<tin[j] && tout[i]>tout[j];
}
int lca(int i, int j) {
	// to append functions take in mind: fdp[i][k] = [i, p_k-1(i)) U [p_k-1(i), p_k(i)]
	if (is_ancestor(i, j)) return i;
	if (is_ancestor(j, i)) return j;
	for (int k = l; k>-1; k--) 
		if (!is_ancestor(dp[i][k], j)) i = dp[i][k];
	return dp[i][0];
}
void init() {
	l = 0;
	while ((1<<l) < n) l++;
	dp.resize(n+1, vi(l+1, -1));
}
