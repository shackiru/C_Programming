#include <stdio.h>
#include <string.h>

struct Date
{
    int date;
    int month;
    int year;
};

enum Gender
{
    Male,
    Female,
};

struct Student
{
	char id[15];
	char name[105];
	Date BirthDate;
    Gender gender;
};

int main()
{
	char monthName[20][5] = {"", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    struct Date tglLahir = {12, 10, 2022};
    printf("%d %s %d\n", tglLahir.date, monthName[tglLahir.month], tglLahir.year);
    
    Student keren;
    strcpy(keren.id, "1234567890");
    strcpy(keren.name, "Keren Hosanna Birila");
    keren.BirthDate.date = 23;
    keren.BirthDate.month = 7;
    keren.BirthDate.year = 2004;
    keren.gender = Female;
    
    printf("ID: %s\n", keren.id);
    printf("Name: %s\n", keren.name);
    printf("BirthDate: %d %s %d\n", keren.BirthDate.date, monthName[keren.BirthDate.month], keren.BirthDate.year);
    printf("Gender: %d\n", keren.gender);

    Student ppti14[40];
    ppti14[0] = keren;

    printf("ID: %s\n", ppti14[0].id);
    printf("Name: %s\n", ppti14[0].name);
    printf("BirthDate: %d %s %d\n", ppti14[0].BirthDate.date, monthName[ppti14[0].BirthDate.month], ppti14[0].BirthDate.year);
    printf("Gender: %d\n", keren.gender);

    return 0;
}
