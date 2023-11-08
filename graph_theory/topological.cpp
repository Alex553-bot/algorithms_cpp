#include <bits/stdc++.h>

using namespace std;
const int N = int(1e5);
vector<int> grafo[N+1];
vector<int> vis(N+1, 0), resp;
int dfs(int i) {
	if (vis[i]) return vis[i]==2;
	vis[i] = 1;
	for (auto a: grafo[i]) 
		if (!dfs(a)) return 0;
	resp.push_back(i);
	vis[i] = 2;
	return 1;
}
int main() {
	int n, m; cin>>n>>m;
	for (auto v: grafo) v.clear();
	while (m-->0) {
		int x, y; cin>>x>>y;
		grafo[x].push_back(y);
	}
	for(int i = 1; i<=n; i++) 
		if (!vis[i] && !dfs(i)) {
			cout<<"IMPOSSIBLE"<<endl;
			return 0;
		}
	reverse(resp.begin(), resp.end());
	for (auto x: resp) 
		cout<<x<<' ';
	cout<<endl;
	return 0;
}
