#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int> 
#define N (int)2e5+1 
vi grafo[N+1], vis(N+1, 0), low(N+1,-1), tin(N+1, -1);
int timer;
set<int> res;
int n, m;
void dfs(int i, int p = -1) {
	int c = 0;	
	vis[i] = 1;
	tin[i] = low[i] = timer++;
	for (auto x: grafo[i]) {
		if (x==p) continue;
		if (vis[x]) low[i] = min(low[i], tin[x]);
		else {
			dfs(x, i);
			low[i] = min(low[i], low[x]);
			if (low[x]>=tin[i] && p!=-1) 
				res.insert(i);
			c++;
		}
	}
	if (p==-1 && c>1) res.insert(i);
}
signed main() {
    // build graph
	timer = 0;
	for (int i= 0; i<n; i++) 
	if (!vis[i]) dfs(i);

	for (auto x: res) cout<<x<<endl;
	res.clear();
    return 0;
}