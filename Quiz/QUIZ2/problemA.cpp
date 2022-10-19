#include <stdio.h>

int main()
{
    int inputCase;
    int gojo;
    int bipay;

    scanf("%d", &inputCase);
    for(int tc = 0; tc < inputCase; tc++)
    {
        scanf("%d %d", &gojo, &bipay);
        printf("Case #%d:", tc + 1);
        
            if(gojo > bipay)
            {
                printf("Go-Jo\n");
            }
            else if(gojo < bipay)
            {
                printf("Bi-Pay\n");
            }
        
    }
    return 0;
}
