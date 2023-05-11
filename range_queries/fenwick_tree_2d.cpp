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
#define N 1000
ll __lcm(ll x,ll y) { return (x*y)/__gcd(x, y);}
void no() {cout<<"no"<<endl;}
void yes() {cout<<"yes"<<endl;}
vector<vl> bit(N+1, vl (N+1, 0)); 
ll low_bit(ll x) {return x&(-x);}
void updatey(ll i, ll j, ll x) {
	while (j<=N) 
		bit[i][j]+=x, j+=low_bit(j);
}
void update(ll i, ll j, ll x) {
	while (i<=N)
		updatey(i, j, x), i+=low_bit(i);
}
ll queryy(ll i, ll j) {
	ll sum =0; 
	while (j>0) 
		sum+=bit[i][j], j-=low_bit(j); 
	return sum;
}
ll query(ll i, ll j) {
	ll sum= 0 ; 
	while (i>0) 
		sum+=queryy(i, j), i-=low_bit(i);
	return sum;
}
void solve() {
	ll n, q; cin >> n >> q;
	fori(i, 0, n) 
		fori(j, 0, n) {
			char c; cin>>c; 
			update(i+1, j+1, c=='*');
		}
	while (q--) {
		ll a, b, c, d;
		cin>>a>>b>>c>>d; 
		ll sum = query(c, d); 
		sum+=query(a-1,b-1); 
		sum-=query(c, b-1); 
		sum-=query(a-1, d);	
		cout<<sum<<endl;
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
