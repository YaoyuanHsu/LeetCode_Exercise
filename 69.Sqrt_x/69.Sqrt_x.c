int mySqrt(int x) {
    int pre = x / 2, now = x / 4;
    if (x == 1)
        return 1;
    // 4 is the largest number that (num^2)/4 <= num
    if (x <= 4)
        return x / 2;
    while (1) {
        // if search window cross the answer, the upper range is the answer
        if (x / pre >= pre)
            return pre;
        // using binary search concept to find the range that sqrt exist
        if (x / now < now || (x / now == now && x % now)) {
            pre = now;
            now /= 2;
        }
        // if we find the range search form both ended
        else {
            pre--;
            now++;
        }
    }
}