#include <stdio.h>

int main()
{
    int inputCase;
    int matrix1, matrix2;
    int numOfMatrix1[105][105];
    int numOfMatrix2[105][105];

    scanf("%d", &inputCase);

    for(int tc = 0; tc < inputCase; tc++)
    {
        scanf("%d %d", &matrix1, &matrix2);

        for(int i = 0; i < matrix1; i++)
        {
            for(int j = 0; j < matrix1; j++)
            {
                scanf("%d", &numOfMatrix1[i][j]);
            }
        }
        for(int i = 0; i < matrix2; i++)
        {
            for(int j = 0; j < matrix2; j++)
            {
                scanf("%d", &numOfMatrix2[i][j]);
            }
        }

        for(int i = 0; i < matrix1 - matrix2 + 1; i++)
        {
            for(int j = 0; j < matrix1 - matrix2 + 1; j++)
            {
                int sum = 0;
                for(int k = 0; k < matrix1; k++)
                {
                    for(int l = 0; l < matrix1; l++)
                    {
                        sum = sum + numOfMatrix1[i + k][j + l] * numOfMatrix2[k][l];
                    }
                }
                printf("%d ", sum);
            }
            printf("\n");
        } 
    }

    return 0;
}