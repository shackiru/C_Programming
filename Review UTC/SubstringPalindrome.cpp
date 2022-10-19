#include <stdio.h>
#include <string.h>

int main()
{
    char word[15];
    char subs[15][15];
    int n = 0;
    
    scanf("%s", word);

    int len = strlen(word);
    for(int i = 1; i <= len; i++)
    {
        for(int j = 0; j <= len - 1; j++)
        {
            char temp[15];
            strncpy(temp, word + j, i);
            temp[j + i]= 0;

			int flag = 0;
			for(int k = 0, m = i - 1; k <= m; k++, m--)
			{
				if(temp[k] != temp[m])
				{
					flag = 1;
				}
			}
		
			if(flag == 0)
			{
				int flag2 = 0;
                for(int k = 0; k < n; k++)
                {
                    if(strcmp(temp, subs[k]) == 0)
                    {
                        flag2 = 1;
                    }
                }

                if(flag2 == 0)
                {
                    strcpy(subs[n], temp);
                    n++;
                }
			}
        }
    }
    printf("%d\n", n);

    return 0;
}
