#include <stdio.h>

int main()
{
	long long arr[105];
	arr[0] = 1;
	arr[1] = 1;
	
	for(int i = 2; i <= 100; i++)
	{
		arr[i] = arr[i-1] + arr[i-2];
	}
	
	int t, n;
	
	scanf("%d", &t);
	for(int tCase = 0; tCase < t; tCase++)
	{
		scanf("%d", &n);
		printf("%lld\n", arr[n]);
	}
	
	return 0;
}
