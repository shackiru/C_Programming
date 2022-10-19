#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *f = fopen("testdata.in", "r");
    
    int a, b;
    
    while(!feof(f))
    {
	    fscanf(f, "%d %d", &a, &b);
	}
	printf("%d\n", a + b);
    fclose(f);

    return 0;
}
