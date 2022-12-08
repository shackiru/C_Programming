#include <stdio.h>

int main()
{
    int arr[10] = {0, 1 ,2 ,3 ,4 ,5, 6, 7, 8, 9,};

    int index = 10;
    int target = 4;

    for(int i = 0; i < index; i++)
    {
        if(arr[i] == target)
        {
            for(int j = 0; j < index; j++)
            {
                arr[j] = arr[j + 1];
            }
            index--;
            break;
        }
    }

    for(int i = 0; i < index; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}