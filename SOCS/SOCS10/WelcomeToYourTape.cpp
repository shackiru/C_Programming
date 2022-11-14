#include <stdio.h>
#include <string.h>

int main()
{
    int cases;
    int personAmount;
    int target;

    char person[105][105] = {};
    char temp[105] = {};

    scanf("%d", &cases);
    getchar();
    for(int tc = 0; tc < cases; tc++)
    {
        scanf("%d %d", &personAmount, &target);
        for(int i = 0; i < personAmount; i++)
        {
            scanf("%s", person[i]); 
        }
        for(int j = 0; j < personAmount - 1; j++)
        {
            for(int k = j + 1; k < personAmount; k++)
            {
                if(strcmp(person[j], person[k]) > 0)
                {
                    strcpy(temp, person[j]);
                    strcpy(person[j], person[k]);
                    strcpy(person[k], temp);
                }	
            }
        }
        printf("Case #%d: %s\n", tc + 1, person[target-1]);  
    }
    return 0;
}
