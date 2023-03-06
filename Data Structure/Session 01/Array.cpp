#include <stdio.h>

int main()
{
	
	// int[a][b] = [a] = row || [b] = column
	 
    int b[3][3] = {
    {0, 1 , 2}, 
    {3, 4, 5},
    {6, 7, 8}
    };

    printf("%d", b[0][2]);

    //Insertion Algorithm
    
    int x[100000];
    for(int i = 0; i < sizeof(x) / 4; i++)
    {
        printf("%d", &x[i]);
    }

    return 0;
}
