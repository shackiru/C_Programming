#include <stdio.h>
#include <stdlib.h>

struct Student
    {
        char name [105];
        int age;
        float percentage;
    };

struct Student* emp = NULL;

int main()
{
    emp = (struct Student*)malloc(sizeof(struct Student));
    emp -> age = 18;

    printf("%d\n", emp->age);

    return 0;
}