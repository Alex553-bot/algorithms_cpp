#include <bits/stdc++.h>
using namespace std;
#define fori(i, ii, n) for (ll i = ii; i<n; i++)
#define N ll(2e5)
typedef long long int ll;
vl dsu(N+1), rank(N+1, 1);
void make_set(ll x) {
	dsu[x] = x;
	rank[x] = 1;
}
ll find(ll x) {
	return x==dsu[x]? x: dsu[x] = find(dsu[x]);
}
void merge(ll i, ll j) {
	a = find(a);
	b = find(b);
	if (a==b) return; 
	if (rank[a]<rank[b])
		swap(a, b);
	dsu[b] = a;
	rank[a]+=rank[b];
}
int main() {
	return 0;
}
