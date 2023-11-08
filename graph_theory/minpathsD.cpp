#include <bits/stdc++.h>
using namespace std; 
#define int long long
vector<pair<int,int>> grafo[N]; 
vector<int> d(N, inf), p(N, -1), vis(N, 0);
void minp(int i) {
	d[i] = 0; 
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q; 
	q.push({0, i}); 
	while (q.size()) {
		int v = q.top().second;
		int a = q.top().first;
		q.pop(); 
		if (a!=d[v]) continue;
		for (auto it: grafo[v]) {
			int x = it.first, y = it.second; 
			if (d[v]+y<d[x]) {
				d[x]  = d[v]+j;
				p[i] = v; 
				q.push({d[i], i});
			}
		}
	}
}
signed main() {
	for (int i= 0; i<N; i++) grafo[i].clear(); 
	int n, m; 
	// build the graph with i 0..N-1
	minp(0); 
	return 0;
}
