/*
	uwu
       alexalvarez123	
*/
#include <bits/stdc++.h>
#define endl '\n'
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define fori(i, ii, n) for (ll i = ii; i<n; i++)
#define forir(i, ii, n) for (ll i = ii; i>n; i--)
#define x first
#define y second
#define pb push_back
#define vl vector<ll>
#define vd vector<double>
#define vcor vector<pair<ll,ll>>
#define all(v) v.begin(),v.end()
#define bs(a, n, s) bitset<n> a(string(s))
#define INF 1000000001
typedef long long int ll;
using namespace std;
#define MOD 1000000007 
#define N 1000000
vl v(N+1, INF);
void update(ll i, ll x, ll n) {
	i+=n; 
	v[i]= x;
	while (i>0) {
		v[i>>1] = min(v[i],v[i^1]);
		i>>=1;
	}
}
ll query(ll i, ll j, ll n) {
	i+=n, j+=n+1;
	ll res = INF;
	while (i<j) {
		if (i&1) res = min(res, v[i++]);
		if (j&1) res = min(res, v[--j]);
		i>>=1, j>>=1;
	}
	return res;
}
void build(ll p, ll n) {
	fori(i, 0, n) 
		cin>>v[i+p];
	forir(i, p-1, 0) 
		v[i] = min(v[i<<1], v[i<<1|1]);
}
void solve() {
	ll n, q; cin>>n>>q;
	ll s = 1;
	while (s<n) s<<=1;
	build(s, n);
	while (q--) {
		ll a, b, c; cin>>a>>b>>c; 
		if (a&1)  
			update(b-1, c, s); 
		else 
			cout<<query(b-1, c-1, s)<<endl;
	}
}
int main() {
	fast;
	ll t;
	t = 1;
	//string s; 
	//getline(cin, s); 
	//t = stoll(s);	
	//cin>>t;
	while (t--) 
		solve();
	return 0;
}
