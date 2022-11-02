#include <stdio.h>
#include <string.h>

struct Student
{
    char name[105];
    int nim;
    int age;
    int postalCode;
    char placeOfBirth[105];
    char dateOfBirth[105];
    char highSchool[105];
    char numOfSibs[105];
    char height[1005];
    int bankAccount;
};

int main()
{
    int n;

    struct Student stud[105];

    scanf("%d", &n);
    for(int tc = 0; tc < n; tc++)
    {
        scanf("%s", stud[tc].name);
		getchar();
		
        scanf("%d", &stud[tc].nim);
        getchar();
        
        scanf("%d", &stud[tc].age);
        getchar();
        
        scanf("%d", &stud[tc].postalCode);
        getchar();
        
        scanf("%s", stud[tc].placeOfBirth);
        getchar();
        
        scanf("%s", stud[tc].dateOfBirth);
        getchar();
        
        scanf("%[^\n]", stud[tc].highSchool);
        getchar();
        
        scanf("%s", stud[tc].numOfSibs);
        getchar();
        
        scanf("%s", stud[tc].height);
        getchar();
        
        scanf("%d", &stud[tc].bankAccount);
        getchar();
        
    }

    for(int i = 0; i < n; i++)	
    {
    	printf("Mahasiswa ke-%d:\n", i + 1);
        printf("Nama: %s\n", stud[i].name);
        printf("NIM: %d\n", stud[i].nim);
        printf("Umur: %d\n", stud[i].age);
        printf("Kode Pos: %d\n", stud[i].postalCode);
        printf("Tempat Lahir: %s\n", stud[i].placeOfBirth);
        printf("Tanggal Lahir: %s\n", stud[i].dateOfBirth);
        printf("Almamater SMA: %s\n", stud[i].highSchool);
        printf("Jumlah Saudara Kandung: %s\n", stud[i].numOfSibs);
        printf("Tinggi Badan: %s\n", stud[i].height);
        printf("NOMOR REKENING: %d\n", stud[i].bankAccount);
    }

    return 0;
}
