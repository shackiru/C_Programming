#include <stdio.h>
#include <string.h>

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
    Student students[3];

    for(int i = 0; i < 3; i++)
    {
        students[i].age = ages[i];
        strcpy(students[i].name, names[i]);
    }

    for(int i = 0; i < 3; i++)
    {
        printf("%s - %d\n", students[i].name, students[i].age);
    }
}