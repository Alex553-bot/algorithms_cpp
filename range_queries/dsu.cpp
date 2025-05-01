struct DSU {
    vi p, rn;
    int n;
    DSU(int N): n(N+1) {
        p.resize(n+1), rn.resize(n+1, 1);
        for (int i = 0; i<=n; i++) p[i] = i;
    } 
    int find(int x) {return p[x] = x==p[x]? x: find(p[x]);}
    void merge(int a, int b) {
        a = find(a), b = find(b);
        if (a==b) return;
        if (rn[a] < rn[b]) swap(a, b);
        p[b] = a;
        rn[a]+=rn[b];
    }
};
