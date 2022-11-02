#include <stdio.h>

int main()
{
	int inputCase;
	int box;
	int boxPrice[1000];
	int max = 0;
	int max2 = 0;
	
	scanf("%d", &inputCase);
	for(int tc = 0; tc < inputCase; tc++)
	{
		scanf("%d", &box);
		
		max = 0;
		max2 = 0;
		int max3 = 0;
		
		for(int i = 0; i < box; i++)
		{
			scanf("%d", &boxPrice[i]);
			
			if(boxPrice[i] > max)
			{
				max3 = max2;
				max2 = max;
				max = boxPrice[i];
			}
			else if(boxPrice[i] > max2)
				{
					max3 = max2;
					max2  = boxPrice[i];
				}			 
			else if (boxPrice[i] > max3)
			{
				max3 = boxPrice[i];
			}
		}
		printf("Case #%d: %d %d", tc + 1, max, max2, max3);
	}
	
	return 0;
}
