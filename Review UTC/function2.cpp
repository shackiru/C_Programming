#include <stdio.h>


int byValue(int a)
{
    a = a + 2;
    return a;
}

int byRef(int a[])
{
	a[0] = a[0] + 5;
	return a[0];
}

int main()
{
    int b = 10;
    int c[10] = {1, 2, 3, 4, 5};
    
    printf("%d\n", b);
    printf("%d\n", byValue(b));
    printf("%d\n", b);
    printf("%d\n", byValue(7));
    printf("%d\n", byRef(c));
    
    for(int i = 0; i < 5; i++)
    {
    	printf("%d ", c[i]);
	}
	printf("\n");
	
	int *p = &b;
	
	printf("%p\n", &b);
	printf("%p\n", p);
	printf("%d\n", *p);
	
	b = 7;
	printf("%d\n", *p);
	
	*p = 15;
	printf("%d\n", b);

    return 0;
}
