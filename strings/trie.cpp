const int MAXSIZE = 26;
struct node {
	int end;
	int grafo[MAXSIZE]
	node() {
		for (int i =0 ; i<MAXSIZE; i++) grafo[i] = 0;
	}
};
vector<node> v(1);
node ini;
void insert(string &s, int i = 0, int j = 0) {
	if (j>size(s)) {
		v[i].end = 1;
		return;
	}
	int to = s[j]-'a';
	if (!v[i].grafo[to]) v[i].grafo[to] = v.size(), v.pb(ini);
	insert(s, v[i].grafo[to], j+1);
}
void erase(string &s, int i = 0, int j = 0) {
	if (j>size(s)) {v[i].end = 0; return;}
	int to = s[j]-'a';
	if (!v[i].grafo[to]) return;
	return erase(s, v[i].grafo[to], j+1);
}
int get(string &s, int i = 0, int j = 0) {
	if (j>size(s)) return v[i].end;
	int to = s[j]-'a';
	if (v[i].grafo[to]) return get(s, v[i].grafo[to], j+1);
}

/*FOR BITS:*/
const int MAXSIZE = 2;
struct node {
    int c;
    int grafo[MAXSIZE];
    node() {grafo[0] = grafo[1] = 0;}
};
vector<node> v(1);
node ini;
void insert(int x, int i = 0, int j = 30) {
    v[i].c++;
    if (j==-1) return;
    int to = (x>>j)&1;
    if (!v[i].grafo[to]) 
        v[i].grafo[to] = v.size(), v.pb(ini);
    insert(x, v[i].grafo[to], j-1);
}
void erase(int x, int i = 0, int j = 30) {
    v[i].c--;
    if (j==-1) return;
    int to = (x>>j)&1;
    erase(x, v[i].grafo[to], j-1);
}
int get(int x, int i = 0, int j = 30) {
	// modify this function based on the problem.
    if (j==-1) return 0;
    int to = 1^((x>>j)&1);
    if (!v[i].grafo[to] || !v[v[i].grafo[to]].c) to ^= 1;
    if (!v[i].grafo[to] || !v[v[i].grafo[to]].c) return 0;
    return (to<<j) + get(x, v[i].grafo[to], j-1);
}
