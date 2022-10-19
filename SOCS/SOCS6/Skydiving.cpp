#include <stdio.h>

int main()
{
    char name[105];
    double height;
    int age;

    for(int tc = 0; tc < 2; tc++)
    {
        scanf("%s %lf %d", name, &height, &age);
        printf("Name %d: %s\n", tc + 1, name);
        printf("Height %d: %.2lf\n", tc + 1, height);
        printf("Age %d: %d\n", tc + 1, age);
    }

    return 0;
}
