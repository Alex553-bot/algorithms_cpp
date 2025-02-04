struct suffix {
    int n, m; vi sa;
    rmq _lcp;
    suffix(string &s): n(s.size()+1), m(max(n+1, 256ll)) {
        s.pb('\0'); buildsa(s); rmq aux(buildlcp(s, sa)); 
        _lcp = aux;
    }
    void radix(vector<pair<pair<int,int>,int>> &a) {
        vector<pair<pair<int,int>,int>> b(n);
        {
            vi cnt(m, 0);
            for (int i = 0; i<n;i ++) cnt[a[i].F.S]++;
            for (int i = 1; i<m; i++) cnt[i]+=cnt[i-1];
            for (int i = n-1; i>-1; i--) b[--cnt[a[i].F.S]] = a[i];
        } {
            vi cnt(m, 0); 
            for (int i = 0; i<n; i++) cnt[b[i].F.F]++;
            for (int i = 1; i<m; i++) cnt[i] += cnt[i-1];
            for (int i = n-1; i>-1; i--) a[--cnt[b[i].F.F]] = b[i];
        }
    }
    void buildsa(string &s) {
        vi p(n), c(n); 
        vector<pair<pair<int,int>,int>> a(n); 
        for (int i=0; i<n; i++) a[i] = {{s[i], 0}, i}; 
        sort(a.begin(), a.end()); 
        for (int i=0; i<n; i++) p[i] = a[i].S;
        c[p[0]] = 0; 
        for (int i = 1; i<n; i++) c[p[i]] = c[p[i-1]]+(a[i].F==a[i-1].F? 0: 1);
        for (int k = 0; (1<<k)<n; k++) {
            for (int i =0 ; i<n; i++) a[i] = {{c[i], c[(i+(1<<k))%n]}, i};
            radix(a);
            for (int i=0 ; i<n; i++) p[i] = a[i].S; 
            c[p[0]] = 0; 
            for (int i =1; i<n; i++) c[p[i]] = c[p[i-1]]+(a[i].F==a[i-1].F? 0:1);
        }
        sa = p;
    }
    vi buildlcp(string &s, vi const &p) {
        vector<int> rank(n, 0);
        for (int i = 0; i < n; i++) rank[p[i]] = i;

        int k = 0;
        vi lcp(n-1, 0);
        for (int i = 0; i < n; i++) {
            if (rank[i] == n - 1) {
                k = 0; continue;
            }
            int j = p[rank[i] + 1];
            while (i + k < n && j + k < n && s[i+k] == s[j+k])
                k++;
            lcp[rank[i]] = k;
            if (k) k--;
        }
        return lcp;
    }
};