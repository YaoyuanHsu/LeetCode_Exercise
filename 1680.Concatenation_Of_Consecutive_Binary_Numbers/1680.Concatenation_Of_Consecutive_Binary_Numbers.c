int concatenatedBinary(int n) {
    int mod = 1e9 + 7;
    long ans = 0;
    int size = 0;
    for (int i = 1; i <= n; i++) {
        if ((i & (i - 1)) == 0)
            size++;
        ans <<= size;
        ans |= i;
        ans %= mod;
    }
    return ans;
}