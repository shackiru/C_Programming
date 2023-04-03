#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Food
{
    char foodName[100];
    int foodPrice;
};

struct Heap
{
    Food *foods; // array yang akan kita buat dynamic
    int maxSize; // capacity (maksimal bisa nampung berapa food)
    int lastIndex; //nandain posisi sekarang( kalau ada data baru, akan dimasukkan ke lastIndex)
}heap;

void initalizeHeap()
{
    heap = {NULL, 2, 1};
    heap.foods = (struct Food*) malloc(sizeof(Food) * heap.maxSize);
    return;
}

void resizeHeap()
{
    //realloc
    heap.maxSize *= 2;
    heap.foods = (Food*) realloc(heap.foods, sizeof(Food) * heap.maxSize);
}

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
    if(left < size && heap.foods[left].foodPrice > heap.foods[largest].foodPrice)
    {
        largest = left;
    }

    //cek apakah punya anak kanan dan anak kanan lebih besar daripada parent (curr)
    if(right < size && heap.foods[right].foodPrice > heap.foods[largest].foodPrice)
    {
        largest = right;
    }

    if(largest != curr)
    {
        //swap
        swap(&heap.foods[largest], &heap.foods[curr]);
        //heapify ulang
        heapify(curr,size);
    }
}

void buildHeap()
{
    //heapify ke semua data yang bukan leaf
    for(int i = heap.lastIndex/2; i>= 1; i--)
    {
        //heapify
        heapify(i, heap.lastIndex);
    }
}


void insertFood(const char *foodName, int foodPrice)
{
    // kalau sudah gmauat tempatnya, resize supaya bisa masukkin lebih banyak data
    if(heap.lastIndex == heap.maxSize)
    {
        resizeHeap();
    }

    strcpy(heap.foods[heap.lastIndex].foodName, foodName);
    heap.foods[heap.lastIndex].foodPrice = foodPrice;
    //tambah posisi
    heap.lastIndex++;

    //buildheap
    buildHeap();
}

void viewFoods()
{
    for(int i = 1; i < heap.lastIndex; i++)
    {
        printf("foods[%d]: %s %d\n", i, heap.foods[i].foodName, heap.foods[i].foodPrice);
    }
    return;
}

//linear search
int searchFood(int foodPrice)
{
    for(int i = 1; i < heap.lastIndex; i++)
    {
        if(heap.foods[i].foodPrice == foodPrice)
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
    swap(&heap.foods[idx], &heap.foods[heap.lastIndex - 1]);
    heap.lastIndex--;

    //buildheap
    buildHeap();
    return;
}

void heapSort()
{
    //pastiin tree kita sudah berbentuk heap
    buildHeap();

    for(int i = heap.lastIndex - 1; i >= 1; i--)
    {
        //swap  
        swap(&heap.foods[i], &heap.foods[1]);
        //heapify
        heapify(1, i);
    }
}

int main()
{
    initalizeHeap();

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