struct rmq {
    vector<vi> v; int n;
    rmq(){}
    rmq(vi a): n(a.size()) {
        int l = 1; while ((1<<l) <= n) l++;
        v.resize(l+1, vi(n));
        v[0] = a;
        for (int i = 0; i<l; i++) 
        for (int j = 0; j<n; j++)
        if (j+(1<<i) < n) v[i+1][j] = min(v[i][j], v[i][j+(1<<i)]); 
    }
    int get(int i, int j) { // [i, j]
        int res = INF; j++;
        for (int k = v.size()-1; k>-1; k--) 
            if (i+(1<<k) <= j) res = min(res, v[k][i]), i+=1<<k; 
        return res;
    }
};