#include <stdio.h>
#include <string.h>

int main()
{
	char nama[100];
	
	scanf("%s", nama);
	if(strcmp(nama,"budi") == 0)
	{
		printf("Selamat Pagi\n");
	}
	
	int flag = 0;
	char budi[] = "budi";
	int len = strlen(budi);
	
	for(int i = 0; i < len; i++)
	{
		if(nama[i] < budi[i])
		{
			flag = -1;
			i = i + len;
		}
		else if(nama[i] > budi[i])
		{
			flag = 1;
			break;
		}
	}
	
	char temp[100];
	int len2 = strlen(nama);
	
	strcpy(temp, nama);
	printf("%s\n", temp);
	
	for(int i = 0; i <= len2; i++)
	{
		temp[i] = nama[i];
	}
	
	printf("%s\n", temp);
	
	
	return 0;
}
