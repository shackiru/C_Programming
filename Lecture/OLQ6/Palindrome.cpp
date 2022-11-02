#include <stdio.h>
#include <string.h>

/* 
    int flag adalah penanda apakah huruf tersebut sama atau berbeda
*/
int main()
{
    int inputCase;
    char word[505];

    scanf("%d", &inputCase);
    getchar();

    for (int tc = 0; tc < inputCase; tc++)
    {
        scanf("%s", word);
        getchar();

        int flag = 0;
        int len = strlen(word);

        for (int i = 0; i < len / 2; i++)
        {
            if(word[i] != word[len- i - 1] )
            {
                flag = 1;
            }
        }

        if(flag == 1)
        {
            printf("Case #%d: Nah, it's not a palindrome\n", tc + 1);
        }
        else
        {
            printf("Case #%d: Yay, it's a palindrome\n", tc + 1);
        }
        
    }
    

    return 0;
}