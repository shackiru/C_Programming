#include <stdio.h>
#include <string.h>

int f(int x)
{

    return x * x;
}

void cetak()
{
    printf("Hello World\n");
}

int min(int a, int b)
{
    if(a < b)
    {
        return a;
    }
    return b;
}

int abs(int a)
{
	if(a < 0)
	{
		return -a;
	}
	return a;
}

char* Upper(char kata[105])
{
    for(int i = 0; kata !='\0'; i++)
    {
        if('a' <= kata[i] && kata [i] <= 'z')
        {
            kata[i] = kata[i] - 32;
        }
    }
    return kata;
}

int main()
{
    cetak();
    printf("%d\n", f(5));
    printf("%d\n", min(90, 100));
    printf("%d\n", abs(-50));
    char kata[] = "dexter";
    printf("%s\n", Upper(kata));

    return 0;
}
