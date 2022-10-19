#include <stdio.h>
#include <string.h>

int linearSearch(int numbers[], int size, int numberToFind){
	for(int x = 0; x < size; x++){
		if(numbers[x] == numberToFind){
			return x;
		}
	}	
	return -1;
}

int linearSearchString(char names[][20], int size, char nameToFind[]){
	for(int x = 0; x < size; x++){
		if(strcmp(names[x], nameToFind) == 0){
			return x;
		}
	}
	return -1;
}
int main(){
	
	int numbers[] = {57,32,9,14,46};
	int size = sizeof(numbers) / sizeof(numbers[0]);
	//search string
	char names[][20] = {"Alicia", "Andi"};
	int size2 = sizeof(names) / sizeof(names[0]);

	char nameToFind[] = "Andi";
	
	int numberToFind = 32;
	int foundIndex = linearSearch(numbers, size, numberToFind);
	int foundIndex2 = linearSearchString(names, size2, nameToFind);
	
	
	printf("Number to find : %d\n", numberToFind);
	if(foundIndex != -1){
		printf("Found Index : %d\n", foundIndex);
	} else {
		printf("Not Found\n");
	}
	
	puts("");
	
	printf("Name to find : %s\n", nameToFind);
	if(foundIndex2 != -1){
		printf("Found Index : %d\n", foundIndex2);
	} else {
		printf("Not Found\n");
	}
	
	return 0;
}
