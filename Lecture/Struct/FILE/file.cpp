#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *f = fopen("testdata.in", "w");
    
    int score, score2;
    
    for(int i = 0; i < 1; i++)
    {
	    scanf("%d %d", &score, &score2);
	}
	printf("%d\n", score + score2);
    fclose(f);

    return 0;
}
