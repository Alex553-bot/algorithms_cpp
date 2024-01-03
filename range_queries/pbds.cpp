/*
	cf: alexalvarez123
		uwu
	problem: Kattis "babyname"
*/
#include <bits/stdc++.h>
#include <bits/extc++.h>
#pragma GCC optimize("O3,unroll-loops")
#define int long long 
#define vi vector<int>
#define fvoices ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'
#define F first
#define S second
#define pb push_back
using namespace std; 
using namespace __gnu_pbds;

typedef tree<string, null_type, less<string>, rb_tree_tag,
		tree_order_statistics_node_update> oset;
const int mod = 998244353;
const int N = 2e6+1;
const int INF = 1e12;
int n, m;
vi bit(N+1, 0);
map<int,int> index, inv;
int gi(string &s) {
	return mapa[stoll(s)];
}
int low_bit(int x) {return x&(-x);}
int query(int i) {
	int sum = 0; 
	while (i) sum+=bit[i], i-=low_bit(i);
	return sum;
}
void upd(int i, int x) {
	while (i<N) bit[i]+=x, i+=low_bit(i);
}
int lower_bound(int i) {
	int k =30, sum =0 , j = 0;
	while (k--) 
		if (j+(1<<k)<N && sum+bit[j+(1<<k)]<i) 
			j+=(1<<k), sum+=bit[j];
	return j+1;
}
void solve() {
	vector<string> queries;
	string s; 
	set<int> ss;
	while (cin>>s) {
		cerr<<s<<endl;
		if (s[0]!='#') {
			int x = stoll(s);
			ss.insert(x);
		}
		queries.pb(s);
		cerr<<'b'<<endl;
	}
	int i = 1;
	for (auto &x: ss) 
		index[x]=i, inv[i] = x, i++;
	cerr<<'a'<<endl;
	for (string &s: queries) {
		if (s[0]=='#') {
			int q = query(N-1);
			q = (q+1)/2;
			cout<<inv[lower_bound(q)]<<endl;
		} else {
			upd(gi(s), 1);
		}
	}
}
signed main() {
	fvoices;
	int T = 1; 
	//cin>>T; 
	while (T--)
		solve();
	return 0;
}
