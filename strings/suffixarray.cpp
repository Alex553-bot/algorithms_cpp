#include <bits/stdc++.h>
using namespace std; 
#define int long long
#define vi vector<int> 
#define S second
#define F first
vi buildSA(string &s, int n) {
	vi p(n), c(n);
	vector<pair<pair<int,int>, int>> a(n);
	for (int i= 0; i<n; i++) a[i] = {{s[i], 0},i};
	sort(a.begin(), a.end()); 
	for (int i= 0; i<n; i++) p[i] = a[i].S; 
	c[p[0]] = 0;
	for (int i= 1; i<n; i++) c[p[i]] = c[p[i-1]]+(a[i].F==a[i-1].F? 0: 1);
	for (int k = 0; (1<<k)<n; k++) {
		for (int i= 0; i<n; i++) a[i] = {{c[i], c[(i+(1<<k))%n]},i};
		sort(a.begin(), a.end()); 
		for (int i = 0; i<n; i++) p[i] = a[i].S; 
		c[p[0]] = 0;
		for (int i= 1; i<n; i++) c[p[i]] = c[p[i-1]]+(a[i].F==a[i-1].F?0: 1);
	}
	return p;
}
signed main() {
	string s; cin>>s;
	s.push_back('$');
	int n = s.size(); 
	vi p = buildSA(s, n);
	for (int i= 0; i<n; i++) cout<<p[i]<<" \n"[i==n-1];
	return 0;
}
