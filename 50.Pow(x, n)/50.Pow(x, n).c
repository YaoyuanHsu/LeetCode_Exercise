double myPow(double x, int n) {
    double res;
    // avoid negative n overflow, we divide by 2 first
    int p = n / 2;

    // simple case
    if (n == 0)
        return 1;
    if (n == 1)
        return x;

    // positive power or not
    if (n < 0) {
        x = 1 / x;
        res = myPow(x, -p);
        // we can not directly use 1/x, it may loose accuracy
    } else
        res = myPow(x, p);

    // half number of power
    if (n % 2 == 0)
        return res * res;
    return res * res * x;
}