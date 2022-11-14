#include <stdio.h>
#include <string.h>

struct Student
{
    char code[105];
    char name[105];
    int age;
};

int main()
{
    struct Student s[1005];
    int testCase; 

    scanf("%d", &testCase);
    for(int tc = 0; tc < testCase; tc++)
    {
        scanf("%s", s[tc].code);
        getchar();
        
        scanf("%[^\n]", s[tc].name);
        getchar();

        scanf("%d", &s[tc].age);
        getchar();
    }

    int findCases, target;
    
    scanf("%d", &findCases);
    for(int i = 0; i < findCases; i++)
    {
        scanf("%d", &target);

        printf("Query #%d:\n", i + 1);
        printf("ID: %s\n", s[target - 1].code);
        printf("Name: %s\n", s[target - 1].name);
        printf("Age: %d\n", s[target - 1].age);
    }
    return 0;
}