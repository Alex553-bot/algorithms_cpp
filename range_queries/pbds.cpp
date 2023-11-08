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
int f(string &s, string &t, oset &ss) {
	if (ss.size()==0) return 0;
	auto ita = ss.lower_bound(s);
	auto itb = ss.lower_bound(t);
	int a = ita==ss.end()?ss.size(): ss.order_of_key(*ita);
	int b = itb==ss.end()?ss.size(): ss.order_of_key(*itb);
	if (b<a) return 0;
	return b-a;
}
void solve() {
	int T, x, res; 
	oset tre[2];
	for (int i=0 ; i<2; i++) tre[i].clear();
	while (true) {
		cin>>T; 
		if (!T) return;
		string s, t; 
		cin>>s;
		if (T==1) {
			cin>>x; x--;
			tre[x].insert(s);
		} else if (T==3) {
			cin>>t>>x; res =0 ;
			if (!x) 
				for (int i=0 ; i<2; i++) 
					res+=f(s, t, tre[i]);
			else res = f(s, t, tre[x-1]);
			cout<<res<<endl;	
		} else 
			for (int i= 0; i<2; i++) 
				tre[i].erase(s);
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
