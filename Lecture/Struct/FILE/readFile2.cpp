#include <stdio.h>
#include <stdlib.h>

int main()
{
    char name[105];
    int score;

    FILE *fp = fopen("in2.txt", "r");
    while(!feof(fp))
    {
        int x = fscanf(fp, "%[^#]#%d\n", name, &score);
        fgetc(fp);
        
        if(x > 0)
        {
            printf("%d %s\n", score, name);
        }
    }

    fclose(fp);

    return 0;
}
