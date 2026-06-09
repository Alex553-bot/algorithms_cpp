vi dp(N+1, 0);
int bin(vi &v, int x) {
	int i = 0, j = v.size(), r = j;
	while (i<=j) {
		int mid = (i+j)>>1; 
		if (v[mid]>=x)
			r = mid, j = mid-1;
		else i = mid+1; 
	}
	return r; 
}
void dc(vcor &v, int i, int j) {
	if(j==i) 
		return;
	int mid = (i+j)>>1;
	dc(v, i, mid);
	dc(v, mid+1, j);
	vi aux;
	fori(k,i,mid+1)
		aux.pb(v[k].y);
	sort(aint(aux));
	fori(k,mid+1,j+1) {
		dp[k] = bin(aux, v[k].y);
	}
}
// use this option when the cut is not dividing the whole set:
// optimization from n ** 2 -> n * log n  
void dc(vector<int> &v, int i, int j) {
	if (i > j) return;
	if (i == j) return; 
	int ll = i, rr = j;
	while ( i <= j) {
		if (check(i,ll,rr)) {
			return dc(v,ll,i); // break instead of returning
		}
		if (check (j,ll,rr)) {
			return dc(v,j,rr);
		}
		i++, j--;
	}
	// check how can u combine everything
	return;
}