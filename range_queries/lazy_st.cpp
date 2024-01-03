#include <bits/stdc++.h>
using namespace std; 
#define vi vector<int>
const int N = 1e5+1;
const int value = 1e17; 
vi t(4*N, value), d(4*N, 0);
int n, k; 
int combine(int left, int right) {
    return min(left, right); 
}
void apply(int &f, int &g) {
    f += g;
}
void propagate(int i) {
    if (i<<1>=2*k+n) return;
    if (i<k) apply(t[i], d[i]);
    if (i<<1>=k) apply(t[i<<1], d[i]), apply(t[i<<1|1], d[i]);
    else apply(d[i<<1], d[i]), apply(d[i<<1|1], d[i]);
    d[i] = 0;
}
void upd(int i, int lc, int rc, int l, int r, int x) {
    if (lc==l&&rc==r) {
        if (i>=k) apply(t[i], x), t[i>>1] = combine(t[i], t[i^1]);
        else apply(d[i], x);
    }
    else {
        if (i>=k) return;
        int mid = (lc+rc)>>1;
        if (l<mid) upd(i<<1, lc, mid, l, min(r, mid), x);
        if (r>=mid) upd(i<<1|1, mid, rc, max(mid, l), r, x);
        propagate(i<<1), propagate(i<<1|1); 
        t[i] = combine(t[i<<1], t[i<<1|1]);
    }
}
int query(int i, int lc, int rc, int l, int r) {
    if (d[i]) propagate(i);
    if (lc==l&&rc==r) return t[i];
    else {
        if (i>=k) return value;
        int mid = (lc+rc)>>1;
        int res = value;
        if (l<mid) res = combine(res, query(i<<1, lc, mid, l, min(mid, r)));
        if (r>=mid) res = combine(query(i<<1|1, mid, rc, max(l, mid), r), res);
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
    return 0;
}