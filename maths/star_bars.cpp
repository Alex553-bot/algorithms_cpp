// fa -> factorial, ifa -> inverse factorial mod something
// n: pelotas, k: cajas
// el problema es: x1+x2+⋯+xn=k , xi≥0 => combinatoria(n+k-1, k)
int C(int n, int k) {
    if (n < k ) return 1;
    return fa[n] * ifa[k] % mod * ifa[n-k] % mod;
}
int SB(int n, int k) {return C(n+k-1, k-1);}
