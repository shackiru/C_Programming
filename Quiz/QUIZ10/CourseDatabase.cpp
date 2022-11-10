#include <stdio.h>
#include <string.h>

struct Course
{
    char code[105];
    char name[105];
    int credit;
};

int main()
{
    struct Course c[1005];
    int cases;

    scanf("%d", &cases);
    for(int tc = 0; tc < cases; tc++)
    {
        scanf("%s", c[tc].code);
        getchar();

        scanf("%[^\n]", c[tc].name);
        getchar();

        scanf("%d", &c[tc].credit);
        getchar();
    }

    int findCases, target;
    scanf("%d", &findCases);
    for(int i = 0; i < findCases; i++)
    {
        scanf("%d", &target);

        printf("Query #%d:\n", i + 1);
        printf("Code: %s\n", c[target - 1 ].code);
        printf("Name: %s\n", c[target - 1].name);
        printf("Credits: %d\n", c[target - 1].credit);
    }
    return 0;
}
