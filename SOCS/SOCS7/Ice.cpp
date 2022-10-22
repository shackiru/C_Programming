#include <stdio.h>

int abs(int a) 
{ 
	return a < 0 ? -a : a; 
}

void ice()
{
	int testCase;
	
	FILE *f = fopen("testdata.in", "r");

	while(fscanf(f, "%d", &testCase) != EOF)
	{
		int amountCase;
		int perimeter;
		int area;
		
		for(int i = 0; i < testCase; i++)
		{
			fscanf(f, "%d", &amountCase);
			int array[amountCase];
			
			perimeter = 0;
			area = 0;

			for(int j = 0; j < amountCase; j++)
			{
				fscanf(f, "%d", &array[j]);
				if(j > 0)
				{
					perimeter += 2 * abs(array[j] - array[j - 1]);
				}
				area += (array[j] * 4);
			}
			perimeter += 2 * (array[0] + array[amountCase - 1] + (2 * amountCase));
			printf("Case #%d: %d %d\n", i + 1, perimeter, area);
		}
	}
	fclose(f);
}

int main()
{
	ice();
	
	return 0;
	
}

