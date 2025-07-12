// Problem: 
/*
Your task is to count the number of integers between [0, n] 
where no two adjacent digits are the same.
*/
// ** all states where ith > 0 are intial -1 and ith = 1 by default
int dp[N][10][10][2]; // ith, prev. digit, digit, trailing zeros
int fi(int i, int antd, int d, int tz = 0) {
    if (antd == d && !(d==0 && tz)) return 0;
    if (dp[i][antd][d][tz]!=-1) return dp[i][antd][d][tz];
    dp[i][antd][d][tz] = 0;

    for (int di = 0; di<10; di++)
        dp[i][antd][d][tz] += fi(i-1, d, di, tz & (!di));
    return dp[i][antd][d][tz];
}
int f(string &s, int i, int tz = 0) {
    if (i<0) return 1;
    int res = 0;
    if (s[i] != s[i+1] || (tz && s[i]=='0')) 
        res += f(s, i-1, tz & (s[i]=='0'));
    for (int d = s[i]-'0'-1; d >= 0; d--) {
        int ttz = tz & (d==0);
        res += fi(i, s[i+1]-'0', d, ttz);
    }
    return res;
}
int f(int n) { // principal function
    if (n<0) return 0;
    string s = to_string(n);
    reverse(s.begin(), s.end()); s.pb('0');
    return f(s, s.size()-2, 1);
}