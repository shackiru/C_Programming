#include <stdio.h>

int main()
{
    int inputCase, month;
    double interest;
    long long money;

    scanf("%d", &inputCase);

    for(int tc = 0; tc < inputCase; tc++)
    {
        scanf("%lld %lf %d", &money, &interest, &month);
        printf("Case #%d:\n", tc + 1);

        for(int i = 0; i < month; i++)
        {
            money = money + money * interest / 100.0 / 12.0 * .8;
            printf("%d %lld\n", i + 1, money);
        }
    }

    return 0;
}