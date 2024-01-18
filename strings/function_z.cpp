#include <bits/stdc++.h>
using namespace std; 
#define int long long
#define vi vector<int>
vi funz(string &s) {
    int n = s.size(); 
    vi v(n);
    	int l = 0, r = 0;
	for (int i= 1; i<n; i++) {
		if (i<r) v[i] = min(r-i, v[i-l]);
		while (i+v[i]<n && s[v[i]]==s[i+v[i]]) v[i]++;
		if (i+v[i]>r) l = i, r = i+v[i];
	}
	return v;
}
signed main() {
    return 0;
}