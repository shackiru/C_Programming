#include <stdio.h>

void printNumbers(int numbers[], int size)
{
    for(int x = 0; x < size; x++)
    {
        if(x == size - 1)
        {
            printf("%d", numbers[x]);
        }
        else
        {
            printf("%d ", numbers[x]);
        }
    }
    printf("\n");
}

void bubbleSort(int numbers[], int size)
{
    for(int x = 0; x < size - 1; x++)
    {
        printf(" x = %d\n", x);
        for(int y = 0; y < size - 1; y++)
        {
            if(numbers[y] > numbers[y + 1])
            {
                int temp = numbers[y + 1]; // temp untuk menampung value dari numbers y + 1
                numbers[y +  1] = numbers[y]; // lalu numbers y + 1 diisi value numbers y (karena numbers y + 1 valuenya ada di temp, jadi numbers y + 1 kosong dan bisa diisi value numbers y)
                numbers[y] = temp; // untuk menampung value temp dari value numbers y + 1 sebelumnya
            }
            printf(" y = %d => ", y);
            printNumbers(numbers, size);
        }
    }
}

void selectionSort(int numbers[], int size)
{
    int smallestValueIndex;

    for(int x = 0; x < size; x++)
    {
        smallestValueIndex = x;
        printf("x  = %d = >", x);

        for(int y = x + 1; y < size; y++)
        {
            if(numbers[y] < numbers[smallestValueIndex])
            {
                smallestValueIndex = y;
            }
        }
        if(smallestValueIndex != x)
        {
            int temp = numbers[smallestValueIndex];
            numbers[smallestValueIndex] = numbers[x];
            numbers[x] = temp;
        }
        printNumbers(numbers, size);
    }
}

void insertionSort(int numbers[], int size)
{
    int valueToBeChecked, y;
    for(int x = 0; x < size; x++)
    {
        valueToBeChecked = numbers[x];
        y = x - 1;

        while(y >= 0 && numbers[y] < valueToBeChecked)
        {
            numbers[y + 1] = numbers[y];
            y--;
        }

        numbers[y + 1] = valueToBeChecked;
    }
}

int main()
{
    int numbers[] ={2, 10, 5, 3, 1};
    int size = sizeof(numbers)/sizeof(numbers[0]);

    printf("Before Sort : ");
    printNumbers(numbers, size);


    // bubbleSort(numbers, size);
    selectionSort(numbers, size);
    insertionSort(numbers, size);

    printf("After Sort : ");
    printNumbers(numbers, size);

    return 0;
}