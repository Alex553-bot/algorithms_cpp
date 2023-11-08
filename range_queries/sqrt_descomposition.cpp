#include <bits/stdc++.h>
using namespace std;
#define N ll(1e4)
typedef long long int ll;
ll n = 0; 
vector<ll> a, b;
ll s;
int main() {
	cin>>n; 
	a.resize(n, 0);
	s = sqrt(n+.0)+1;
	b.resize(s, 0);
	for(ll i = 0; i<n; i++) cin>>a[i];
	// preprocessing:
	for(ll i = 0; i<n; i++) 
		b[i/s]+=a[i];
	// queries: 
	while (m--) 

	return 0;
}
