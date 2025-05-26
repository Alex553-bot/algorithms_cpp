struct rmq { // query complexity O(1)
    vector<vi> v;
    vi log2;
    int n;
    rmq() {}
    rmq(vi a): n(a.size()+10) {
        int L = 32 - __builtin_clz(n);
        log2.resize(n+1);

        log2[1] = 0;
        for (int i = 2; i <= n; i++) log2[i] = log2[i>>1] + 1;

        v.resize(L, vi(n));
        v[0] = a;
        for (int k = 1; k<L; k++)
        for (int i = 0; i+(1<<k)<=n; i++) 
            v[k][i] = min(v[k-1][i], v[k-1][i+(1<<(k-1))]);
    }
    int get(int l, int r) { // [l, r]
        int k = log2[r - l + 1];
        return min(v[k][l], v[k][r - (1 << k) + 1]);
    }
};