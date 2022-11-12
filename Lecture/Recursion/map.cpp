#include <stdio.h>

struct Point
{
    int x, y;
};

void move(int x, int y, int step, int board[10][10], char map[15][15])
{
    if(x < 0 || x > 9 || y < 0 || y > 9)
    {
        return;
    }

    if(map[x][y] == '#')
    {
        return;
    }

    if(board[y][x] <= step)
    {
        return;
    }

    board[y][x] = step;
    move(x - 1, y, step + 1, board, map);
    move(x + 1, y, step + 1, board, map);
    move(x, y - 1, step + 1, board, map);
    move(x, y + 1, step + 1, board, map);
}

int main()
{
    int board[10][10];
    char map[15][15] = 
    {
        "..........",
        "...#..#...",
        "...####...",
        "......#...",
        "...#..#...",
        "####......",
        "..........",
        "....######",
        "..........",
        "..........",
        "..........",
    };

    Point src, dst;

    for(int i = 0; i < 15; i++)
    {
        for(int j = 0; j < 15; j++)
        {
            board[i][j] = 100;
        }
    }
    scanf("%d %d %d %d", &src.x, &src.y, &dst.x, &dst.y);
    move(src.x, src.y, 0, board, map);
    printf("%d\n", board[dst.y][dst.x]);

    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            printf("%2d |", board[i][j]);
        }
    }

    return 0;
}
