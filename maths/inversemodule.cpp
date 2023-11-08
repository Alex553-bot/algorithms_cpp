#include <bits/stdc++.h> 
using namespace std;
typedef long long int ll;
ll m = 1e9+7;
ll binpow(ll a, ll n) {
	ll res = 1;
	while (n) {
		if (n&1) res*=a, res%=m;
		a*=a, a%=m;
		n>>=1;
	}
	return res;
}
int main() {
	ll n; cin>>n; 
	cout<<"Inverse modular: "<<binpow(n, m-2)<<endl;
	return 0;
}
