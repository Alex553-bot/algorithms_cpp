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
vl dp(N+1, 0);
ll bin(vl &v, ll x) {
	ll i = 0, j = v.size(), r = j;
	while (i<=j) {
		ll mid = (i+j)>>1; 
		if (v[mid]>=x)
			r = mid, j = mid-1;
		else i = mid+1; 
	}
	return r; 
}

void dc(vcor &v, ll i, ll j) {
	if(j==i) 
		return;
	ll mid = (i+j)>>1;
	dc(v, i, mid);
	dc(v, mid+1, j);
	vl aux;
	fori(k,i,mid+1)
		aux.pb(v[k].y);
	sort(all(aux));
	fori(k,mid+1,j+1) {
		dp[k] = bin(aux, v[k].y);
	}
}
void solve() {
	ll n; cin >> n; 
	vcor v(n);
	fori(i,0,n)
		cin>>v[i].x>>v[i].y;
	sort(all(v));
	dc(v, 0, n-1);
	fori(i, 0, v.size())
		cout<<v[i].x<<' '<<v[i].y<<": "<<dp[i]<<endl;
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
