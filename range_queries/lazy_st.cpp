const int N = 1e5+1;
const int value = 1e17; 
vi d(4*N), t(4*N);
int n, k; 
int combine(int a, int b) {
    return a+b;
}
void apply(int &a, int b, int len, int piv) {
    a+=b*len+piv*(len-1)*len/2;
}
void propagate(int i, int len) {
    if (!d[i] || i>=2*k+n) return;
    apply(t[i], d[i], len, f[i]);
    if ((i<<1)<2*k+n) {
        d[i<<1]+=d[i], d[i<<1|1]+=d[i]+f[i]*len/2;
        f[i<<1]+=f[i], f[i<<1|1]+=f[i];
    }
    d[i] = f[i] = 0;
}
void upd(int i, int lc, int rc, int l, int r, int x) {
    if (l==r) return;
    propagate(i, rc-lc);
    if (lc==l&&rc==r) {
        d[i]+=x;f[i]++; 
        propagate(i, rc-lc);
    } else {
        assert(lc!=rc-1);
        int mid = (lc+rc)>>1;
        if (l<mid) upd(i<<1, lc, mid, l, min(r, mid), x);
        if (r>=mid) upd(i<<1|1, mid, rc, max(mid, l), r, x+mid-lc);
        propagate(i<<1, mid), propagate(i<<1|1, mid);
        t[i] = combine(t[i<<1], t[i<<1|1]);
    }
}
int query(int i, int lc, int rc, int l, int r) {
    if (l==r) return 0;
    propagate(i, rc-lc);
    if (lc==l&&rc==r) return t[i];
    else {
        assert(lc!=rc-1);
        int mid = (lc+rc)>>1, res =0 ;
        if (l<mid) res = combine(res, query(i<<1, lc, mid, l, min(mid, r)));
        if (r>=mid) res = combine(query(i<<1|1, mid, rc, max(l, mid), r), res);
        propagate(i<<1, mid-lc), propagate(i<<1|1, mid-lc);
        t[i] = combine(t[i<<1], t[i<<1|1]); 
        return res;
    }
}
void build() {
    for (int i=0 ; i<n;i ++) t[i+k] = 0;
    for (int i = k-1; i; i--) t[i] = combine(t[i<<1], t[i<<1|1]);
}
signed main() {
    // entries: n and q
    k = 1; 
    while (k<=n) k<<=1;
    build();
    // upd o query : 
    // f(1, 0, k, l, r, value);
    return 0;
}
