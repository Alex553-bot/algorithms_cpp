#include <bits/stdc++.h>
using namespace std;
#define vl vector<int>
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define N int(1e5)
#define cor pair<int,int>
#define vcor vector<cor>
#define INF 1e9
vcor grafo[N+1];
vl d(N+1, INF), p(N+1, -1), vis(N+1, 0);
int n;
void dijs(int i) {
	d[i]=0;
	d[i] = 0; 
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	pq.push({0, i});
	while (pq.size()) {
		int v = pq.top().S, dd = -pq.top().F;
		pq.pop(); 
		if (dd!=d[v]) continue;
		for (auto edge: grafo[v]) {
			int to = edge.F, len = edge.S; 
			if (d[v]+len<d[to]) {
				d[to] = d[v]+len;
				pq.push({-d[to],to});
			}
		}
	}
}
vl path(int i, int j) {
	int v = j;vl res;
	while (v!=i) res.push_back(v), v = p[v];
	res.push_back(i);
	return res;
}
int main() {
	int m;
	cin>>n>>m;
	while (m--) {
		int a, b, c; 
		cin>>a>>b>>c;
		grafo[a].push_back({b, c});
		grafo[b].push_back({a,c});
	}
	dijs(1);
	if (p[n]==-1) {
		cout<<-1<<endl;
		return 0;
	}
	vl res = path(1, n);
	reverse(res.begin(), res.end());
	for (int i = 0; i<res.size(); i++) 
		cout<<res[i]<<" \n"[i==res.size()-1];
	return 0;
}
