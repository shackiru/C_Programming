#include <stdio.h>
#define MAX_N 100

void input(int num[], int *idx)
{
    int numInput;
    scanf("%d", &numInput);
    num[*idx] = numInput;
    (*idx)++;
}

void print(int num[], int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("Num: %d\n", num[i]);
    }
}

void delFront(int num[], int *size)
{
    for(int i = 0; i < *size; i++)
    {
        num[i] = num[i + 1];
    }
    (*size)--;
}

void delBack(int *size)
{
    (*size)--;
}

int delElement(int target, int num[], int *size)
{
    for(int i = 0; i < *size; i++)
    {
        if(num[i] == target)
        {
            for(int j = i; j < *size; j++)
            {
                num[j] = num[j + 1];
            }
            (*size)--;
            return i;
        }
    }
    return -1;
}

int main()
{
    int num[MAX_N];
    int n;
    int i = 0;
    int idx = 0;
    
    scanf("%d", &n);
    while(i < n)
    {
        input(num, &i);
    }

    print(num, i);
    printf("\n");
    
    // delFront(num, &i);
    // delBack(&i);

    delElement();
     
    print(num, i);
}
