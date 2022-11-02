#include <stdio.h>
#include <string.h>


struct Lecturer
{
	char lecCode[35];
	char lecName[105];
	char lecGender[105];
	int lecStud;
};

struct Student
{
	char studCode[35];
	char studName[35];
	char studGender[35];
	char studDad[35];
	char studMom[35];
	int studSibs;	
};

int main()
{
	int numCase;
	int searchData;
	struct Lecturer lect[105];
	struct Student stud[105][105];
	
	scanf("%d", &numCase);
	getchar();
	
	for(int tc = 0; tc < numCase; tc++)
	{
		scanf("%s", lect[tc].lecCode);
		getchar();
		
		scanf("%s", lect[tc].lecName);
		getchar();
		
		scanf("%s", lect[tc].lecGender);
		getchar();
		
		scanf("%d", &lect[tc].lecStud);
		getchar();
		
		for(int i = 0; i < lect[tc].lecStud; i++)
		{
			scanf("%s", stud[tc][i].studCode);
			getchar();
			
			scanf("%s", stud[tc][i].studName);
			getchar();
			
			scanf("%s", stud[tc][i].studGender);
			getchar();
			
			scanf("%s", stud[tc][i].studDad);
			getchar();
			
			scanf("%s", stud[tc][i].studMom);
			getchar();
			
			scanf("%d", &stud[tc][i].studSibs);
			getchar();	
		}
	}
	
	scanf("%d", &searchData);
	getchar();
			
	printf("Kode Dosen: %s\n", lect[searchData - 1].lecCode);
	printf("Nama Dosen: %s\n", lect[searchData - 1].lecName);
	printf("Gender Dosen: %s\n", lect[searchData - 1].lecGender);
	printf("Jumlah Mahasiswa: %d\n", lect[searchData - 1].lecStud);
	
	for(int j = 0; j < lect[searchData - 1].lecStud; j++)
	{
		printf("Kode Mahasiswa: %s\n", stud[searchData - 1][j].studCode);
		printf("Nama Mahasiswa: %s\n", stud[searchData - 1][j].studName);
		printf("Gender Mahasiswa: %s\n", stud[searchData - 1][j].studGender);
		printf("Nama Ayah: %s\n", stud[searchData - 1][j].studDad);
		printf("Nama Ibu: %s\n", stud[searchData - 1][j].studMom);
		printf("Jumlah Saudara Kandung: %d\n", stud[searchData - 1][j].studSibs);
	}
	
	return 0;
}
