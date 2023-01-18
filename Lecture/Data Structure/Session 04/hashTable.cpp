#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 150

struct Hash{
    char name[50];
    int age;
    struct Hash *next; 
};

struct Hash *hashMap[SIZE] = {};

int hashCode(char name[]) {
    // function pembuatan key
    int key = 0;
    for(int i = 0; i < strlen(name); i++){
        key += name[i];
    }
    key %= SIZE;
    return key;
}

struct Hash* createHash(const char name[], int age){
    struct Hash *newNode = (struct Hash*) malloc(sizeof(Hash));
    strcpy(newNode->name, name);
    newNode->age = age;
    newNode->next = NULL;
    return newNode;
}

void insertData(char name[], int age) {
    struct Hash *newNode = createHash(name, age);
    int key = hashCode(name);
    struct Hash *prev = NULL;
    struct Hash *iter = hashMap[key];

    while(iter) {
        prev = iter;
        iter = iter->next;
    }
    // Jika list belum ada isi maka akan diisi pertama kali
    if(prev == NULL) {
        hashMap[key] = newNode;
    } else {
    // Jika list sudah terisi maka akan pushtail
        prev->next = newNode;
    }
}

void deleteData(char name[]) {
    int key = hashCode(name);
    struct Hash *iter = hashMap[key];
    // cek apakah yang akan dihapus sudah berisi
    // case 1 dimana pada hash tersebut hanya ada 1 element
    if(iter && strcmp(name, iter->name) == 0) {
        printf("%s %d\n", iter->name, iter->age);
        free(iter);
        hashMap[key] = NULL;
        printf("Data Deleted\n");
        return;
    }
    // case 2 dimana pada hash ada lebih dari element
    while(iter) {
        if(iter->next && strcmp(name, iter->next->name) == 0) {
            struct Hash *temp = iter->next;
            iter->next = iter->next->next;
            free(temp);
            printf("Data Deleted\n");
        }
        iter = iter->next;
    }
    printf("Data Not Found\n");
}

void displayData() {
    for(int i = 0; i < SIZE; i++) {
        if(hashMap[i] != NULL) {
            struct Hash *iter = hashMap[i];
            while(iter) {
                printf("%s - %d\n", iter->name, iter->age);
                iter = iter->next;
            }
        }
    }
}

void menu() {
    printf("Menu\n");
    printf("1. Insert Data\n");
    printf("2. Delete Data\n");
    printf("3. Display All Data\n");
    printf("4. Cancel\n");
}

int main() {
    int input = 0;
    do {
        menu();
        scanf("%d", &input);
        switch(input) {
            case 1: {
                char name[50];
                int age;
                scanf("%s", name);
                scanf("%d", &age);
                insertData(name, age);
                break;
            }
            case 2: {
                char name[50];
                scanf("%s", name);
                deleteData(name);
                break;
            }
            case 3: 
                displayData();
                break;
            case 4:
                break;
            default:
                printf("Error Input\n");
                break;
        }
    } while(input != 4);
    printf("THANK YOU\n");
}