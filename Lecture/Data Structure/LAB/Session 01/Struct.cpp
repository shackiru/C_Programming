#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

struct Student
{
    char name[100];
    int age;
};

int main()
{
    Student s1;
    strcpy(s1.name, "Felix");
    s1.age = 20;

    int ages[] = {20, 15 , 17};
    char names[][100] {"Supandi", "Felix", "Nathasya"};
    Student *students[3];

    for(int i = 0; i < 3; i++)
    {
        students[i] = (Student*) malloc (sizeof(Student));
        students[i]->age = ages[i];
        strcpy(students[i]->name, names[i]);
    }

    free(students[1]);
    students[1] = NULL;


    for(int i = 0; i < 3; i++)
    {
        if(students[i] != NULL)
        {
            printf("%d. %s - %d\n", i, students[i]->name, students[i]->age);
        }
        else
        {
            printf("%d. No Value\n", i);
        }
    }
}
