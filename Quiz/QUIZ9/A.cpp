#include <stdio.h>

int main(){

	int testCase;
	scanf("%d", &testCase);

	long long int arr[10005] = {0};

	arr[0] = 0;

	for(int i = 1; i <= testCase; i++)
	{
		scanf("%lld", &arr[i]);
		arr[i] += arr[i - 1];
	}

	int sample;
	long long int findSample;
	scanf("%d", &sample);

	for(int i = 0; i < sample; i++)
	{
		scanf("%lld", &findSample);

		int index = -1;

		for(int j = testCase; j > 0; j--)
		{
			for(int k = 0; k <= j - 1; k++)
			{
				if(arr[j] - arr[k] <= findSample)
				{
					if(j - k > index)
					{
						index = j - k;
						break;
					} 
					else if(j - k <= index){
						break;
					}
				}
			}
		}

		printf("Case #%d: %d\n", i + 1, index);
	}
	return 0;
}