const int primes[2] = {127, 229};
const int mods[2] = {1000000007, (1ll<<31)-1};
vi pows[2], invs[2];
int n, m;
int binpow(int b, int e, int m) {
    int res = 1; 
    for(; e; e>>=1, b = b*b%m)
    if (e&1) res = res*b%m;
    return res;
}
int inv(int b, int m) {return binpow(b, m-2, m);}
void init() {
    for (int i=0; i<2; i++) {
        pows[i].resize(N, 1), invs[i].resize(N, 1);
        for (int j= 1; j<N;j ++) {
            pows[i][j] = (pows[i][j-1]*primes[i])%mods[i];
            if (j==1) invs[i][j] = inv(pows[i][j], mods[i]);
            else invs[i][j] = (invs[i][j-1]*invs[i][1])%mods[i];
        }
    }
}
struct Hash{ // USO: init() [1 vez] y luego usar normal
    int n; vi v[2];
    Hash(string &s): n(s.size()) {
        for (int i = 0; i<2; i++) v[i].resize(n);
        for (int i = 0; i<2;i ++) 
        for (int j = 0; j<n; j++) v[i][j] = (s[j] * pows[i][j]%mods[i] + (j? v[i][j-1]: 0))%mods[i];
    }
    int fh(int i, int j, int k) {
        return (v[k][j]-(i? v[k][i-1]: 0)+mods[k])%mods[k] * invs[k][i] % mods[k];
    }
    int get(int i, int j) { // get [i, j]
        return fh(i, j, 0) + fh(i, j, 1) * 1000000000ll;
    }
};