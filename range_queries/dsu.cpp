struct DSU {
    vi p;
    DSU(int ni) {p.resize(n+1, -1);} 
    int find(int x) {return p[x] < 0? x: p[x] = find(p[x]);}
    void merge(int a, int b) {
        a = find(a), b = find(b);
        if (a==b) return;
        if (p[a] > p[b]) swap(a, b);
        p[a]+=p[b];
        p[b] = a;
    }
    int siz(int x) {return p[find(x)];}
};
