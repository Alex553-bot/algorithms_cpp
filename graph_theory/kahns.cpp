#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define int long long 
#define N (int)1e6
#define pb push_back
vi grafo[N], inc(N, 0), topo;
int n, m, y; 
void kanh() {
    priority_queue<int,vi,greater<int>> pq;
    for (int i= 1; i<=n; i++) 
    if (!inc[i]) pq.push(i);
    y = 0;
    while (pq.size()) {
        int i = pq.top();
        topo.pb(i);
        pq.pop();
        for (auto x: grafo[i])
        if (!(--inc[x])) pq.push(x);
        y++;
    }
}
signed main() {
    // build graph
    cin>>n>>m; 
    while (m--) {
        int a, b; cin>>a>>b;
        grafo[a].pb(b);
        inc[b]++;
    }
    kanh();
    if (y!=n) {cout<<"Ciclo"<<endl;}
    else {cout<<"Topological"<<endl;}
    return 0;
}