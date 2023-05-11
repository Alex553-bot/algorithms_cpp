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
ll find(vl &v, ll x, ll i) {
	ll n = v.size();
	//cout<<i<<endl;
	if (i>n || v[i]<x) return -1;
	if (v[i]==x) return i;
	ll a = i*2+1, b = i*2+2;
	return max(find(v,x,a),find(v,x,b));
}
void insert(vl &v) {
	ll i = v.size()-1; 
	while (i>0) {
		ll p = i; 
		if (!(p&1)) p--;
		p>>=1;
	       	if (v[p]>v[i]) break;
		swap(v[p], v[i]); 
		i = p;
	}
} 
void del(vl &v, ll i) {
	v[i] = -1;
	ll a = i*2+1,b=i*2+2, n=v.size();
	ll max = -1;
	if(a<n) max = a;
	if(b<n) 
	       if(v[max]<v[b])
		max = b;
	if(max!=-1)
		swap(v[i], v[max]), del(v,max);
	else {
		swap(v[i],v[n-1]);
		v.pop_back();
	}
}
void solve() {
	ll n;
	vl v; cin>>n;
	fori(i,0,n) {
		ll x; cin>>x;
		v.pb(x);
		insert(v);
	}
	del(v,3);
	n = v.size();
	fori(i,0,n)
		cout<<v[i]<<" \n"[i==n-1];
	cout<<find(v,2,0)<<endl;
}
int main() {
	//fast;
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
