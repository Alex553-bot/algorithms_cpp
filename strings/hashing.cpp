#include <bits/stdc++.h> 
using namespace std;
typedef long long int ll;
ll m = 1e9+7;
ll hashing(string s, ll p) {
	ll a = 1, res =0 ;
	for (ll i= 0; i<s.size())
		res += s[i]*a%m, a*=p, a%=m;
	return res;
}
int main() {
	// p must be a prime number: 31 is a good choice
	cin>>m;
	string s; cin>>s;
	ll hash = hashing(s, m);
	cout<<hash<<endl;
	return 0;
}
