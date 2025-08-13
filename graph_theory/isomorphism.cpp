#define pii pair<int,int>
struct nodo{
    // struct para calcular grafos isomorfos
    vector<vi> grafo; 
    vector<pii> dp; // {hash, isCentroid}
    vi pows;
    int base;
    nodo(int n): base(2) {
        grafo.resize(n+1);
        dp.resize(n+1); pows.resize(n+10, 1);
        for (int i = 1; i<pows.size(); i++) pows[i] = pows[i-1]*base%mod;
    }
    int f(int x, int l) {return (x*base%mod + pows[l-1] + mod) % mod;}
    int combine(int r, int x, int l) {return (r*pows[l]%mod + x + mod) % mod;}
    void addEdge(int i, int j) {
        grafo[i].pb(j);
        grafo[j].pb(i);
    }
    pii dfs(int i, int p = -1) {
        int res = 0, s = 1;

        vector<pii> aux;
        
        for (auto &to: grafo[i])
            if (to != p) aux.pb(dfs(to,i));
        
        sort(aux.begin(), aux.end());
        
        for (auto &x: aux) res = combine(res, x.F, x.S), s+=x.S;
        
        return dp[i] = {f(res, s), s};
    }
    void dfs2(int i, int p = -1, pii res = {0, 0}) {
        vector<array<int,3>> va;

        if (res.S) va.pb({res.F, res.S, p});
        for (auto &to: grafo[i]) 
            if (to != p && dp[to].S) 
                va.pb({dp[to].F, dp[to].S, to});

        sort(va.begin(), va.end());

        pii left(0, 0), right(0, 0); 
        dp[i].S = va.size() > 1;
        for (auto &[x, l, _]: va) 
            right.F = combine(right.F, x, l), right.S += l, dp[i].S &= va[0][1] == l;
        dp[i].F = f(right.F, right.S+1);

        pii ant = {0, 0};

        for (auto &[x, l, to]: va){
            left.F = combine(left.F, ant.F, ant.S);
            left.S += ant.S;

            right.S -= l;
            right.F = (right.F - pows[right.S]*x%mod + mod)%mod;
            
            res.F = combine(left.F, right.F, right.S);
            res.S = left.S + right.S + 1;

            res.F = f(res.F, res.S);

            if (to != p) dfs2(to, i, res);

            ant = {x, l};
        }
    }
};
int check_isomorph(auto &g1, auto &g2) {
    g1.dfs(1); g2.dfs(1);
    g2.dfs2(1); // re-root;
    int n = g1.dp.size();
    for (int i = 1; i<=n; i++)
        if (g1.dp[1] == g2.dp[i]) return 1;

    return 0;
}