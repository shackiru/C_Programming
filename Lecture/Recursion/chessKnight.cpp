#include <stdio.h>

struct Point
{
    int x, y;
};

void move(int x, int y)
{
    move(x - 1, y - 2);
    move(x + 1, y - 2);
    move(x - 2, y - 1);
    move(x + 2, y - 1);
    move(x - 2, y + 1);
    move(x + 2, y + 2);
    move(x - 1, y + 2);
    move(x + 1, y + 2);
}

int main()
{
    int board[10][10];
    Point src, dst;

    scanf("%d %d %d %d", &src.x, &src.y, &dst.x, &dst.y);

    return 0;
}