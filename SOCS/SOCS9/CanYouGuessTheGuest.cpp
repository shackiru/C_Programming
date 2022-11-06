#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr, int low, int high)
{
    int x = (rand() % (high - low + 1)) + low;

    swap(&arr[low], &arr[x]);
    
    int pivot = arr[low];
    int index = low + 1;

    for(int i = low + 1; i <= high; i++)
    {
        if(arr[i] < pivot)
        {
            swap(&arr[index], &arr[i]);
            index++;        }
    }
    swap(&arr[low], &arr[index - 1]);
    return index - 1;
}   

int quickSort(int *arr, int low, int high)
{
    if(low < high)
    {
        int pivot = partition(arr, low, high);

        quickSort(arr, low, pivot - 1); // Left Partition
        quickSort(arr, pivot + 1, high); // Right Partition
    }
}

int main()
{
    
    int testcase;
    scanf("%d" &testcase);

    for(int tc = 1; tc < testcase; tc++){
        int values[25], answer[5], index = 1, sum = 0, done[25] = {};
        for(int i = 0; i < 25; i++){
            scanf("%d", &values);
            sum += values[i];
        }

        quickSort(isi dewek);

        answer[0] = values[0] / 2;
        done[0] = 1;

        for(int j = 0; index < 5; index++){
            for(j = 0; j < 25 && done[j]; j++){
                continue;
            }

            // pake while juga bisa
            // while(j < 25 && done[j]){
                // j++;
            // }

            answer[index] = values[j] - answer[0];

            for(int i = 0; i < index; i++)
            {
                int count = 0;
                for(int k = 0; k < 25 && count < 2; k++)
                {
                    if(!done[k] && values[k] == (answer[i] + answer[index]))
                    {
                        done[k] = 1;
                        count++;
                    }
                }
            }

            for(int i = 0; i < 25; i++)
            {
                if(!done[i] && values[i] == (answer[index] * 2))
                {
                    done[i] = 1;
                    break;
                }
            }
        }
        printf("Case #%d:", tc);
        for(int i = 0; i < 5; i++)
        {
            printf(" %d", answer[i]);
        }
        printf("\n");
        }
        return 0;
    }
