/*
	a(+x)z u.u 
       alexalvarez123	cf
*/
#include <bits/stdc++.h>
#define endl '\n'
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define fori(i, ii, n) for (ll i = ii; i<n; i++)
#define forir(i, ii, n) for (ll i = ii; i>n; i--)
#define cor pair<ll,ll>
#define x first
#define y second
#define pb push_back
#define vl vector<ll>
#define vd vector<double>
#define vcor vector<pair<ll,ll>>
#define all(v) v.begin(),v.end()
#define bs(a, n, s) bitset<n> a(string(s))
#define INF 1000000001
#define no cout<<"NO"<<endl
#define yes cout<<"YES"<<endl
#define precision(n) fixed<<setprecision(n)
typedef long long int ll;
using namespace std;
#define MOD 1000000007 
#define N ll(2e5)
ll __lcm(ll x,ll y) { return (x*y)/__gcd(x, y);}
ll n,m;
ll binpow(ll a, ll n) {
	ll r = 1; 
	while (n) {
		if (n&1) r*=a, r%=MOD;
		a*=a, a%=MOD;
		n>>=1;
	}
	return r;
}
void solve() {
	ll a, b;
	cin>>a>>b; 
	cout<<binpow(a, b)<<endl;
}
int main() {
	fast;
	ll t; t = 1;
	//string s;getline(cin, s);t = stoll(s);	
	//cin>>t;
	while (t--) solve();
	return 0;
}
