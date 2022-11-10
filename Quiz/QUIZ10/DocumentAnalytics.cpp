#include <stdio.h>

int main()
{
    int manyWord;
    int count = 0;
    int page = 1;
    int flag = 0;
    char word[5005];

    FILE *f = fopen("testdata.in", "r");
    
    fscanf(f, "%d\n", &manyWord);
    while(!feof(f))
    {
        fscanf(f, "%s\n", word);
        if(word[0] != '#')
        {
            count++;
        }
        else if(word[0] == '#')
        {
            if(count < manyWord)
            {
                printf("page %d: %d word(s)\n", page, count);
                flag = 1;
            }
            count = 0;
            page++;
        }
    }
    if(flag == 0)
    {
    	printf("The essay is correct\n");
	}
    return 0;
}
