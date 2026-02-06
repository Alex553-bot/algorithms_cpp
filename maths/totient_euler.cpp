// calculate how many nums less or equal than x are: gcd(x,i) = 1
vector<int> phi(N);
void init() { // calculate for all number [1,N] in O(n*log(log(n)))
	for (int i = 1; i<N; i++) phi[i] = i;
	for (int i = 2; i<N; i++)
	if (phi[i] == i) {
		for (int j = i; j<N;j +=i) 
			phi[j] -= phi[j]/i;
	}
}