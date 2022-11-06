#include<stdio.h>
#include<string.h>

int main(){
	int tc;
	int total[30];
	int result[10] = {0};
	int arr[30];
	int max = 0;
	int min = 20000001;
	int idxMax = -1;
	int idxMin = -1;
	
	for(int i = 0 ; i < 30; i++)
	{
		arr[i] =0 ;
	}
	
	scanf("%d", &tc);
	for(int i = 0; i < tc; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			result[j]=0;
		}
		for(int j = 0; j < 30; j++)
		{
			arr[j] = 0;
			total[j] = 0;
		}

		max = 0;
		min = 20000001;
		idxMax = -1;
		idxMin = -1;

		for(int j = 0; j < 25; j++)
		{
			scanf("%d", &total[j]);
			arr[j]++;

			if(max < total[j])
			{
				max = total[j];
				idxMax = j;
			}

			if(min > total[j])
			{
				min = total[j];
				idxMin = j;
			}

			for(int k = 0; k < j; k++)
			{
				if(total[j] == total[k])
				{
					arr[j]--;
					arr[k]++;
					break;
				}
			}
		}
		printf("Case #%d:", i+1);
		if(arr[idxMax] == 1)
		{
			result[4] = max / 2;
		}
		if(arr[idxMin] == 1)
		{
			result[0] = min / 2;
		}
		if(arr[idxMax] == 4)
		{
			result[4] = max / 2;
			result[3] = max / 2;
		}
		if(arr[idxMin] == 4)
		{
			result[0] = min / 2;
			result[1] = min / 2;
		}
		if(arr[idxMax] == 9)
		{
			result[4] = max / 2;
			result[3] = max / 2;
			result[2] = max / 2;
		}
		if(arr[idxMin] == 9)
		{
			result[0] = min / 2;
			result[1] = min / 2;
			result[2] = min / 2;
		}
		if(arr[idxMax] == 16)
		{
			result[4] = max/ 2;
			result[3] = max/ 2;
			result[2] = max/ 2;
			result[1] = max/ 2;
		}
		if(arr[idxMin] == 16)
		{
			result[0] = min / 2;
			result[1] = min / 2;
			result[2] = min / 2;
			result[3] = min / 2;
		}
		if(arr[idxMin] == 25)
		{
			result[0] = min / 2;
			result[1] = min / 2;
			result[2] = min / 2;
			result[3] = min / 2;
			result[4] = min / 2;
		}		
		
		for(int j = 0; j < 25; j++)
		{
			if((total[j] % 2 == 0)
			&&(arr[j] == 1 || 
			arr[j] == 3 || 
			arr[j] == 5) 
			&& total[j] != max 
			&& total[j] != min)
			{
				for(int k=0; k < 5; k++)
				{
					if(result[k] == 0)
					{
						result[k] = total[j] / 2;
						break;
					}
				}
			}
		}
		for(int j = 0; j < 5; j++)
		{
			for(int k = 0; k < 4 - j; k++)
			{
				if(result[k] > result[k+1]){
					int temp;
					temp = result[k];
					result[k] = result[k+1];
					result[k+1] = temp;
				}
			}
		}
		for(int j = 0; j < 5; j++)
		{
			printf(" %d", result[j]);
		}
		printf("\n");
	}			
	return 0;
}
