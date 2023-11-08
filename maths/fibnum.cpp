#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define fori(i,ii,n) for (ll i = ii; i<n; i++)
struct matrix {
	ll matr[2][2];
	matrix friend operator *(const matrix &a, const matrix &b) {
		matrix c; 
		fori(i, 0, 2) 
		fori(j, 0, 2) {
			c.matr[i][j] = 0;
			fori(k, 0, 2)
				c.matr[i][j]+=a.matr[i][k]*b.matr[k][j];
		}
		return c;
	}
};
matrix binpow(matrix a, ll n) {
	matrix res{{
		{1, 0},
		{0, 1}
	}};
	while (n) {
		if (n&1) res = res*a;
		a = a*a;
		n>>=1;
	}
	return res;
}
ll fast_algorithm(ll n) {
	matrix base{{
		{1, 1},
		{1, 0}
	}};
	return binpow(base, n).matr[0][1];
}
ll naive_algorithm(ll n) {
	ll a = 0, b = 1;
	fori(i, 0, n) {
		ll aux = a+b;
		a = b;
		b = aux;
	}
	return a;
}
int main() {
	ll n, m; cin>>n; m = n;
	cout<<naive_algorithm(n)<<endl;
	cout<<fast_algorithm(m)<<endl;
	return 0;
}
