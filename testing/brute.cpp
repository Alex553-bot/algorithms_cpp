#include <bits/stdc++.h> 
using namespace std; 

signed main() {
	int x; cin>>x;
	int d = 1000; 
	for (int i = 0; i<d;i ++) 
	if ((x - i) % d == 0) cout<<d<<endl, exit(0);
	return 0;
}
