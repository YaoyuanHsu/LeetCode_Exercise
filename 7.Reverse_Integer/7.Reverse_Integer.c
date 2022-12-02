#include <limits.h>

int reverse(int x) {
    int* check = malloc(sizeof(int));
    int negative = (x < 0), first = x % 10, remain = x / 10, res = 0;
    while (remain != 0) {
        // By negative number or not checking whether it will get overflow after times 10
        if (negative ? (INT_MIN / 10 <= res) : (INT_MAX / 10 >= res)) {
            res *= 10;
            // By negative number or not checking whether it will get overflow after plus first
            if (negative ? (INT_MIN - first <= res) : (INT_MAX - first >= res))
                res += first;
            else
                return 0;
        }

        else
            return 0;

        // Re-update first and remain
        first = remain % 10;
        remain = remain / 10;
    }

    // If there still has any un-operating number in first
    if (first != 0) {
        if (negative ? (INT_MIN / 10 <= res) : (INT_MAX / 10 >= res)) {
            res *= 10;
            if (negative ? (INT_MIN - first <= res) : (INT_MAX - first >= res))
                return res += first;
        }

        else
            return 0;
    }

    return res;
}