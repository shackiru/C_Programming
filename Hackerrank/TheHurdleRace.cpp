#include <stdio.h>

int main()
{
    int testCase;
    int min;
    int findMax = 0;
    int array[105];
    
    scanf("%d %d", &testCase, &min);
    for(int i = 0; i < testCase; i++)
    {
	    scanf("%d", &array[i]);
        
        if(array[i] > findMax)
        {
            findMax = array[i];
        }
    }
    printf("%d", findMax - min);
    
    return 0;
}
