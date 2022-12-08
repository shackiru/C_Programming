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

void delElement()
{

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
    delFront(num, &i);
    delBack(&i);
    delBack(&i);
    delBack(&i);
        
    print(num, i);
}
