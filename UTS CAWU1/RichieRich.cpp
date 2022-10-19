#include <stdio.h>

int main()
{
    int n, k;

    int array[100005] = {};
    char word[100005];

    scanf("%d %d", &n , &k);
    getchar();

    scanf("%s", word);
    int flag = 0;

    for(int i = 0, j = n - 1; i <= j; i++, j--)
    {
            if(word[i] < word[j] && k >= 1)
            {
                word[j] == word[i];
                array[i] = 1;
                k--;
            }
            else if(word[i] > word[j] && k >= 1)
            {
                word[j] = word[i];
                array[j] = 1;
                k--;
            }
            else if(word[i] != word[j] && k == 0)
            {
                flag = 1;
            }
    }

    if(flag == 1)
    {
        printf("-1\n");
    }
    else
    {
        for(int i = 0, j = n - 1; i <= j; i++, j--)
        {
            if(word[i] < '9' && word[j] < '9')
            {
                if(word[i] < '9' && word[j] < '9')
                {
                    if(i == j && k >= 1)
                    {
                        word[i] = '9';
                        k--;
                    }
                    else if(array[i] == 0 && array[j] == 0 && k >= 2)
                    {
                        word[i] = '9';
                        word[j] = '9';

                        k -= 2;
                    }
                    else if(array[i] == 1 && array[j] == 0 && k >= 1)
                    {
                        word[i] = '9';
                        word[j] = '9';  
                        k--;
                    }
                    else if(array[i] == 0 && array[j] == 1 && k >= 1)
                    {
                        word[i] = '9';
                        word[j] = '9';
                        k--;
                    }
                }
            }
        }
        printf("%s\n", word);
    }

    return 0;
}