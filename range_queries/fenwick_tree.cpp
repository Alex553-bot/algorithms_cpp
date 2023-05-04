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
#define N 200000
ll __lcm(ll x,ll y) { return (x*y)/__gcd(x, y);}
void no() {cout<<"no"<<endl;}
void yes() {cout<<"yes"<<endl;}
vl bit(N+1, 0);
ll low_bit(ll x) {return x&(-x);}
ll query(ll i) {
	ll sum= 0;
	while (i>0) 
		sum+=bit[i], i-=low_bit(i);
	return sum;
}
void update(ll i, ll x) {
	while (i<=N) 
		bit[i]+=x, i+=low_bit(i);
}
void solve() {
	ll n, q; cin>>n>>q; 
	fori(i, 0, n) {
		ll x; cin>>x; 
		update(i+1, x);
	}
	while (q--) {
		ll a, b, c; cin>>a>>b>>c; 
		if (a&1) {
			ll aux = query(b)-query(b-1); 
			update(b, -aux); 
			update(b, c); 
		}
		else 
			cout<<query(c)-query(b-1)<<endl;	
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
