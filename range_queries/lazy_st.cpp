struct ST {
    vi d, t;
    int k, n;
    ST(int Ni): k(1), n(Ni+1) {
        while (k<n) k<<=1;
        d.resize(4*n), t.resize(4*n);
    }
    int combine(int a, int b) {return min(a, b);}
    void apply(int &a, int b, int len) {a = b;}
    void propagate(int i, int len) {
        if (!d[i] || i >= k+n) return;
        apply(t[i], d[i], len);
        if ((i<<1) < k+n) 
            d[i<<1]+=d[i], d[i<<1|1]+=d[i];
        d[i] = 0; 
    }
    void upd(int i, int lc, int rc, int l, int r, int x) {
        if (l==r) return;
        propagate(i, rc-lc);
        if (lc==l && rc == r) {
            apply(d[i], x, rc-lc);
            propagate(i, rc-lc);
        } else {
            int mid = (lc+rc)>>1;
            if (l < mid) upd(i<<1, lc, mid, l, min(r, mid), x);
            if (r>=mid) upd(i<<1|1, mid, rc, max(l, mid), r, x);
            propagate(i<<1, mid-lc), propagate(i<<1|1, mid-lc);
            t[i] = combine(t[i<<1], t[i<<1|1]);
        }
    }
    int query(int i, int lc, int rc, int l, int r) {
        if (l==r) return INF;
        propagate(i, rc-lc);
        if (lc == l && rc == r) return t[i];
        else {
            int mid = (lc+rc)>>1, res = INF;
            if (l < mid) res = combine(res, query(i<<1, lc, mid, l, min(mid, r)));
            if (r >= mid) res = combine(query(i<<1|1, mid, rc, max(mid, l), r), res);
            propagate(i<<1, mid-lc), propagate(i<<1|1, mid-lc);
            t[i] = combine(t[i<<1], t[i<<1|1]);
            return res;
        }
    }// always: [i, j)
    void upd(int i, int j, int x) {upd(1, 0, k, i, j, x);}
    int query(int i, int j) {
        return query(1, 0, k, i, j);
    }
};
