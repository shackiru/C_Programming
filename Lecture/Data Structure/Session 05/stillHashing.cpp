#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXSIZE 5

struct hash
{
    
}h;

char hashTable[MAXSIZE][50] = {};

int hashing(char s[])
{
    return s[0] - 'a';
}

void initTable()
{
    for(int i = 0; i < MAXSIZE; i++)
    {
        strcpy(hashTable[i] , "");
    }
}

void insert(char s[])
{
    int key = hashing(s) % MAXSIZE;
    // data masih kosong
    if(strcmp(hashTable[key], "") == 0)
    {
        strcpy(hashTable[key], s);
    }
    else
    {
    //sudah ada isi, maka: linear prob
        int counter = key + 1;
        while(strcmp(hashTable[counter], "") != 0 && counter != key)
        {
            counter++;
            if(counter == MAXSIZE)
            {
                counter = counter % MAXSIZE;
            }
        }
        if(counter == key)
        {
            printf("Table penuh!\n");
            return;
        }
        strcpy(hashTable[counter], s);
        return;
    }
}

void del(int key)
{
    strcpy(hashTable[key], "");
}

void print()
{
    for(int i = 0; i < MAXSIZE; i++)
    {
        if(strcmp(hashTable[i], "") != 0)
        {
            printf("%d -> %s\n", i, hashTable[i]);
        }
    }
}

int main()
{
    char string[50];
    initTable();
//    scanf("%s", string);
    for(int i = 0; i < 6; i++)
    {
        scanf("%s", string);
        getchar();
        insert(string);
        print();
    }

    return 0;
}
