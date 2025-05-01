#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define double long double
#define vi vector<int>
#define pb push_back
#define F first 
#define S second
#define endl '\n'
#define hana ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
const int N = 1e6+10;
const int INF = 1e17+1;
const int mod = 1e9+7;
//const int mod = 998244353;
const double eps = 1e-6;
typedef pair<int,int> pii;
vi grafo[N], v(N), tin(N), tout(N);
vi primes = {2};
int n, L, l, timer = 0;
vector<vi> dp, dpa;
void dfs(int i, int p) {
    tin[i] = timer++;
    dp[i][0] = p;
    if (i!=p) dpa[i][0] = v[p]*v[i];
    else dpa[i][0] = v[i];
    for (int j = 1; j<=l; j++) {
        dp[i][j] = dp[dp[i][j-1]][j-1];
        int pac = dp[i][j], pan = dp[i][j-1];
        /// dpa[i][j] = dpa[i][j-1]  *
        // mantiene [i, p(i)] * [p(i), p(p(i))] / v[p(i)] 
        dpa[i][j] = dpa[i][j-1] * dpa[dp[i][j-1]][j-1] / v[dp[i][j-1]];
    }
    for (auto &to: grafo[i])
    if (to!=p) dfs(to, i);
    tout[i] = timer++;
}
int is_ancestor(int i, int j) {return tin[i]<tin[j] && tout[i]>tout[j];}
array<int,2> lca(int i, int j) {
    if (i==j) {return {i, v[i]};}
    if (is_ancestor(j, i)) {
        // caso especial: 
        int res = v[j];
        for (int k = l; k>-1; k--) 
        if (!is_ancestor(dp[i][k], j)) {
            res = res*dpa[i][k]/v[dp[i][k]];
            i = dp[i][k];
        }
        return {dp[i][0], res};
    }
    if (is_ancestor(i, j)) return {i, v[i]};
    for (int k = l; k>-1; k--) 
    if (!is_ancestor(dp[i][k], j))
        i = dp[i][k];
    return {dp[i][0], -1};
}
void init() {
    l = 1; 
    while ((1ll<<l) < n) l++;
    dp.resize(n+1, vi(l+1, -1));
    dpa.resize(n+1, vi(l+1, 1));

    vi a(71); 
    for (int i = 3; i<=70; i++)
    if (!a[i]) {
        primes.pb(i);
        for (int j = i*i; j<=70; j++) a[j] = 1;
    } 
}
int f(int x) {
    vector<array<int,2>> v;
    for (auto prime: primes) {
        if (prime*prime > x) break;
        int c = 0;
        while (x%prime == 0) x/=prime, c++;
        if (c) v.pb({prime, c});
    }
    if (x) v.pb({x, 1});
    x = 1;
    for (auto &[y, c]: v)
    if (c&1) x*=y;
    return x;
}
void solve() {
    cin>>n>>L;
    init();
    for (int i = 1; i<=n; i++) grafo[i].clear(), cin>>v[i], v[i] = f(v[i]);
    for (int i = 1; i<n; i++) {
        int a, b; cin>>a>>b;
        grafo[a].pb(b);
        grafo[b].pb(a);
    }
    dfs(1, 1);

    int q; cin>>q;
    while (q--) {
        int a, b; cin>>a>>b;
        int d = lca(a, b)[0];
        int res = lca(a, d)[1] * lca(b, d)[1] / v[d];
        res = f(res);
        int c = 0, li = 1;
        while (li < res) li*=L, c++;
        cout<<c<<endl;
    }
}
signed main() {
    hana;
    init();
    int T = 1; //cin>>T;
    while (T--) solve();
    //while (!cin.eof()) solve();
    return 0;
}