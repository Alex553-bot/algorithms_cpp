/*

based on the problem :

given 'n' numbers, n <= 5e5, and 1 <= a_i <= 1e9 I want to know the result of the following formula:
sum_i(sum_j(f(i,j)*(j-i+1))) for all 1 <= i <= j <= n 

You could need a range where the i-th bit is 1 then: 
if I'm even then count odd
otherwise I count even

If you need a range where i-th is always 0 then: 
if I'm even then count even 
otherwise I count odd

*/
void solve() {
	for (int ki = 0; ki < 31; ki ++) {
        int mask = (1ll<<ki), pos = 0;
        vi dp(2), cnt(2); 
        // dp stores the sum of lens and count the number of subarrays 
        // that fit the previous rules
        int opt = 0, a = 0;
        for (int i = 0; i<n;i ++) {
            int ant = pos&1;

            dp[ant]+=i-1; // you always stores in the previous state
            cnt[ant]++; // check if you want to include subarray of length 1 or not (this one includes them)
            if (v[i]&mask) pos++;

            int ac = pos&1; ac^=1;

            a += cnt[ac]*i - dp[ac];
        }
        if (!pos) a = 0;
        a%=mod;
        res = (res + a*mask%mod)%mod;
    }

}