#include <stdio.h>

int main()
{
	int testCase;
	int amountCase;
	int array[105];
	int perimeter, area;
	
	FILE *f = fopen("testdata.in", "r");
	fscanf(f, "%d", &testCase);
	
	for(int tc = 0; tc < testCase; tc++)
	{
			fscanf(f, "%d", &amountCase);
			for(int i = 0; i < amountCase; i++)
			{
				fscanf(f, "%d", &array[i]);
				perimeter += ;
			}
			
	}
	
}
