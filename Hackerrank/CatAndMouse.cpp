#include <stdio.h>

int abs(int a)
{
    if(a < 0)
    {
        return -a;
    }
    return a;
}

int main()
{
    int testCase;
    int pos1, pos2, pos3;
    
    scanf("%d", &testCase);
    for(int i = 0; i < testCase; i++)
    {
        scanf("%d %d %d", &pos1, &pos2, &pos3);
            
        int posA = abs(pos1 - pos3);
        int posB = abs(pos2 - pos3);
    
        if(posA < posB)
        {
            printf("Cat A\n");
        }
        else if(posB < posA)
        {
            printf("Cat B\n");
        }
        else
        {
            printf("Mouse C\n");
        }
    }
    return 0;
}

