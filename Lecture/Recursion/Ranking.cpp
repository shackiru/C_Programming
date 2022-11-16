#include <stdio.h>
#include <stdlib.h>

struct Student
{
    char name[15];
    int score;
    int rank;
}ppti14[1005];

void swap(Student *a, Student *b)
{
    Student temp = *a;
    *a = *b;
    *b = temp;
}

int partition(Student arr[], int low, int high)
{
    int x = rand() % (high - low + 1) + low;
    swap(&arr[x], &arr[low]);

    Student pivot = arr[low];
    int index = low + 1;

    for(int j = low + 1; j <= high; j++)
    {
        if(pivot.score < arr[j].score)
        {
            swap(&arr[j], &arr[index]);
            index++;
        }
    }
    swap(&arr[low], &arr[index - 1]);
    return index - 1;
}

void quickSort(Student arr[], int low, int high)
{
    if(low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    int n;
    FILE *f = fopen("testdata.in", "r");

    while(fscanf(f, "%d\n", &n) != EOF)
    {
        for (int i = 0; i < n; i++)
        {
            fscanf(f, "%[^#]#%d", ppti14[i].name, &ppti14[i].score);
            fgetc(f);
        }
        quickSort(ppti14, 0, n - 1);
        ppti14[0].rank = 1;
        for(int k = 1; k < n; k++)
        {
            if(ppti14[k].score == ppti14[k - 1].score)
            {
                ppti14[k].rank = ppti14[k - 1].rank;
            }
            else
            {
                ppti14[k].rank = k + 1;
            }
        }

        for(int j = 0; j < n; j++)
        {
            printf("%2d %2d %s\n", ppti14[j].rank, ppti14[j].score, ppti14[j].name);
        }

        int findName;
        char target[50];

        fscanf(f, "%d", &findName);
        for(int i = 0; i < findName; i++)
        {
            fscanf(f, "%[^\n]\n", target);
        }
    }
        fclose(f);
    
    return 0;
}
