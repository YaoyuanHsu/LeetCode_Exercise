/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

int guessNumber(int n) {
    if (n == 1)
        return 1;
    int top = n, num = n / 2, down = 1, guessResult = guess(num), tmp;
    while (1) {
        // Equal
        if (guessResult == 0)
            return num;
        // Higher
        if (guessResult == -1) {
            top = num;
            num = floor(num / 2.0 + down / 2.0);
        }
        // Lower
        if (guessResult == 1) {
            down = num;
            num = ceil(num / 2.0 + top / 2.0);
        }
        guessResult = guess(num);
    }
}