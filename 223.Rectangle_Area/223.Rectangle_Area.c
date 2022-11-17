#define Square(x1, x2, y1, y2) ((x2 - x1) * (y2 - y1))
#define Large1(a1, b1) (a1 < b1 ? b1 : a1)
#define Min2(a2, b2) (a2 < b2 ? a2 : b2)

int CrossDistance(int a1, int a2, int b1, int b2) {
    if ((b1 > a2) || (a1 > b2))
        return 0;
    return Min2(a2, b2) - Large1(a1, b1);
}

int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
    return Square(ax1, ax2, ay1, ay2) + Square(bx1, bx2, by1, by2) -
           CrossDistance(ax1, ax2, bx1, bx2) * CrossDistance(ay1, ay2, by1, by2);
}