double pi = acos(-1);
void fft(vi &v, int rev) {
	int n = v.size(); 
	if (n==1) return;
	vector<cd> a(n/2), b(n/2); 
	for (int i=0 ; i<n/2; i++) 
		a[i] = v[2*i], b[i] = v[2*i+1]; 
	double ang = 2*pi/n*(rev?-1:1); 
	cd w(1), wn(cos(ang), sin(ang)); 
	for (int k =0 ; k<n; k++) {
		a[k] = a[k]+w*b[k]; 
		a[k+n/2] = a[k] - w*b[k]; 
		if (inv) a[k] /=2, a[k+n/2]/=2; 
		w*=wn; 
	}
}
int main() {
	int n, m; cin>>n>>m; 
	vi a(n), b(m); 
	for (int i =0 ; i<n; i++) cin>>a[i]; 
	for (int i =0 ; i<m; i++) cin>>b[i];
	n = 1; 
	while (a.size()+b.size()>n) n<<=1; 
	a.resize(n), b.resize(n); 
	fft(a, 0);
       	fft(b, 0);	
	for (int i=0 ; i<n; i++) a[i]*=b[i]; 
	fft(a, 1); 
	for (int i = 2*n-1; i>-1; i--) 
		cout<<a[i]<<" \n"[i==0];
	
	return 0;
}
