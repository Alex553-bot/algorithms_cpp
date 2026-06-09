int __lcm(int x,int y) { return (x*y)/__gcd(x, y);}
int n,m;
int binpow(int base, int exp) {
	int res = 1; 
	for (; exp; exp>>=1, base = (base*base)%MOD)
	if (exp&1) res = (res*base)%MOD;
	return res;
}
// if exp is really huge and m is prime then a^k -> a^(k%mod)
// Euler theorem: no restrictions neither(base,exp,mod): 
int binpow(int base, int exp, int mod) {
	int phi_m = get_totient(mod); // count how many number i less than m satisfies this cond: gcd(i,m)=1

	if (exp > phi_m) {
		k = phi_m + ( k % phi_m );
	}
	return binpow(base,exp);
}