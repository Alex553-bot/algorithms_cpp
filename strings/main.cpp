#include <bits/stdc++.h> 
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ln '\n'
int cumple(int x) {
	int y = x;
	while (x) {
		if (x%10>2) return -1;
		x/=10;
	}
	return y;
}
int ff(int x) {
	cout<<x<<' ';
	int res = 0;
	while (x) res = res*10+x%3, x/=10;
	cout<<res<<ln;
	return cumple(res);
}
signed main() {
	fast;
	int t, n, res; cin>>t; 
	while (t--) {
		map<int, int> mapa;
		mapa[0] = 0;
		cin>>n; res = 0;
		while (n--) {
			int x, y; cin>>x;
			y = ff(x);
			if (y==-1) continue;
			set<pair<int,int>> s;
			for (auto ac: mapa) {
				int z = y+ac.first;
				z = cumple(z);
				if (z==-1) continue;
				s.insert({z, x+ac.second});
				res = max(res, x+ac.second);
			}
			for (auto it: s) 
				mapa[it.first] = max(mapa[it.first], it.second);
		}
		cout<<res<<ln;
	}
	return  0;
}
