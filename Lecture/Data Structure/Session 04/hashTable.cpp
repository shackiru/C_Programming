#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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
    printf("Menu Added!\n");
}

void deleteData(char name[]) {
    int key = hashCode(name);
    struct Hash *iter = hashMap[key];
    // cek apakah yang akan dihapus sudah berisi
    // case 1 dimana pada hash tersebut hanya ada 1 element
    if(iter && strcmp(name, iter->name) == 0) {
        free(iter);
        hashMap[key] = NULL;
        printf("Menu Deleted!\n");
        return;
    }
    // case 2 dimana pada hash ada lebih dari element
    while(iter) {
        if(iter->next && strcmp(name, iter->next->name) == 0) {
            struct Hash *temp = iter->next;
            iter->next = iter->next->next;
            free(temp);
            printf("Menu Deleted!\n");
        }
        iter = iter->next;
    }
    printf("Menu Not Found\n");
}

void displayData() {
    printf("%15s\n", "Restauran Menu");
    printf("+========================================+\n");
    printf("| %-23s | %-13s |\n", "Name", "Price");
    printf("+========================================+\n");
    for(int i = 0; i < SIZE; i++) {
        if(hashMap[i] != NULL) {
            struct Hash *iter = hashMap[i];
            while(iter) {
                printf("| %-20s | %-10d |\n", iter->name, iter->age);
                iter = iter->next;
            }
        }
    }
    printf("+========================================+\n");
}

void menu() {
    system("cls");
    printf("Restaurant Data\n");
    printf("1. Add Menu\n");
    printf("2. Remove Menu\n");
    printf("3. Display Menu\n");
    printf("4. Cancel\n");
    printf("What do you want to do? ");
}

int main() {
    char input = 0;
    do {
        do {
            menu();
            scanf("%c", &input);
            getchar();
        } while(!isdigit(input) || ((input - '0') < 0 || (input - '0') > 4));
        switch(input) {
            case 1: {
                char name[50];
                int age;
                printf("Menu Name: ");
                scanf("%s", name);
                printf("Price: ");
                scanf("%d", &age);
                insertData(name, age);
                break;
            }
            case 2: {
                char name[50];
                printf("Menu to Remove: ");
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