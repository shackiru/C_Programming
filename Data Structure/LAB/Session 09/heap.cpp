#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXSIZE 100

struct Food
{
    char foodName[100];
    int foodPrice;
}foods[MAXSIZE];

//mnandain posisi sekarang( kalau ada data baru, akan dimasukkan ke lastIndex)
int lastIndex = 1;

void swap(Food * a, Food * b)
{
    Food temp = *a;
    *a = *b;
    *b = temp;

    return;
}

//curr adalah data yang mau dicek sekarang
void heapify(int curr, int size)
{
    //cari anak kiri dan kanan indexnya dimana
    int left = (2 * curr);
    int right = (2 * curr) + 1;
    int largest = curr;

    //cek apakah punya anak kiri dan anak kiri lebih besar daripada parent (curr)
    if(left < size && foods[left].foodPrice > foods[largest].foodPrice)
    {
        largest = left;
    }

    //cek apakah punya anak kanan dan anak kanan lebih besar daripada parent (curr)
    if(right < size && foods[right].foodPrice > foods[largest].foodPrice)
    {
        largest = right;
    }

    if(largest != curr)
    {
        //swap
        swap(&foods[largest], &foods[curr]);
        //heapify ulang
        heapify(curr,size);
    }
}

void buildHeap()
{
    //heapify ke semua data yang bukan leaf
    for(int i = lastIndex/2; i>= 1; i--)
    {
        //heapify
        heapify(i, lastIndex);
    }
}


void insertFood(const char *foodName, int foodPrice)
{
    strcpy(foods[lastIndex].foodName, foodName);
    foods[lastIndex].foodPrice = foodPrice;
    //tambah posisi
    lastIndex++;

    //buildheap
    buildHeap();
}

void viewFoods()
{
    for(int i = 1; i < lastIndex; i++)
    {
        printf("foods[%d]: %s %d\n", i, foods[i].foodName, foods[i].foodPrice);
    }
    return;
}

//linear search
int searchFood(int foodPrice)
{
    for(int i = 1; i < lastIndex; i++)
    {
        if(foods[i].foodPrice == foodPrice)
        {
            return i;
        }
    }
    return -1;
}

void deleteFood(int foodPrice)
{
    //indexnya / posisi data yang kita delete dimana?
    int idx = searchFood(foodPrice);

    if(idx == -1)
    {
        return;
    }

    // swap data yang mau di delete dengan data paling terkahir
    swap(&foods[idx], &foods[lastIndex - 1]);
    lastIndex--;

    //buildheap
    buildHeap();
    return;
}

void heapSort()
{
    //pastiin tree kita sudah berbentuk heap
    buildHeap();

    for(int i = lastIndex - 1; i >= 1; i--)
    {
        //swap  
        swap(&foods[i], &foods[1]);
        //heapify
        heapify(1, i);
    }
}

int main()
{
    insertFood("Sate Padang", 30000);
    insertFood("Sate Padang", 28000);
    insertFood("Sate Padang", 36000);
    insertFood("Sate Padang", 34000);
    insertFood("Sate Padang", 26000);
    insertFood("Sate Padang", 44000);
    insertFood("Sate Padang", 48000);
    viewFoods();

    printf("\n\nAfter Delete:\n");
    deleteFood(36000);
    viewFoods();

    heapSort();
    printf("\n\nAfter Sort: \n");
    viewFoods();


    return 0;
}