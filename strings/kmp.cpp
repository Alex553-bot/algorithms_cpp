#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int> 
vi kmp(string &s) { // t+'%'+s
    int n = s.size();
	vi v(n);
	for (int i = 1; i<n; i++) {
		int j = v[i-1];
		while (j && s[i]!=s[j]) j = v[j-1];
		if (s[i]==s[j]) j++;
		v[i] = j;
	}
	return v;
} 
signed main() {
    return 0;
}