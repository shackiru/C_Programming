#include <stdio.h>

//Case ini setiap ada perpindahan/swap maka count ditambah sesuai price

void bubbleSort()
{
    
}

int main()
{
    int testCase;
    int caseNum;
    int price;
    int num[10005];

    scanf("%d", &testCase);
    for(int tc = 0; tc < testCase; tc++)
    {
        scanf("%d %d", &caseNum, &price);
        for(int i = 0; i < caseNum; i++)
        {
            scanf("%d", &num[i]);
        }
    }

    return 0;
}