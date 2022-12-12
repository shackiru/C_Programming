#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student
{
    char name[100];
    int age;
} People;

int main()
{
    Student s1;
    s1.age = 20;

    Student *sp1 = (Student*) malloc (sizeof(People));
    strcpy(sp1->name, "Supandi");

    sp1->age = 5;
    printf("%s - %d\n", sp1->name, sp1->age);

    free(sp1);
    sp1 = NULL;
    printf("%s - %d\n", sp1->name, sp1->age);
}