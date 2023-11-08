#include <bits/stdc++.h>
using namespace std; 
#define int long long 
signed main() {
	double l = 0, f = 1e9; 
	while (f-l>1e-8) {
		double mid1 = l+(f-l)/3; 
		double mid2 = f-(f-l)/3; 
		if (f(mid1)>f(mid2)) l = mid1; 
		else f = mid2;
	}
	cout<<f(l)<<endl;
	return 0;
}
