#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll ext_gcd(ll a, ll b, ll &x, ll &y) {
	if (!b) {
		x = 1, y = 0;
		return a;
	}
	ll xs, ys; 
	ll g = ext_gcd(b, b%a, xs, ys);
	x = ys, y = xs-ys*(a/b);
	return g;
}
int main() {
	ll n, a, b; cin>>n>>a>>b;
	ll x, y; 
	ll g = ext_gcd(a, b, x, y);
	x *= n/g, y*=n/g;
	for (int i = -3; i<4; i++) {
		ll xs = x+i*(b/g), ys = y-i*(a/g);
		cout<<xs<<' '<<ys<<'\n';
	}
}
