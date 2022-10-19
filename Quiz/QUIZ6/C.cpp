#include <stdio.h>

int main()
{
	int n;
	int a, b;
	
	scanf("%d", &n);
	for(int tc = 0; tc < n; tc++)
	{
		scanf("%d %d", &a, &b);
		while(a != b && a != 1)
		{
			if(a == 1)
			{
				a = 1;
			}
			else if(a % 2 == 0)
			{
				a = a / 2;
			}
			else
			{
				a = a * 3 + 1;
			}
		}
		
		if(a == b)
		{
			printf("Case #%d: YES\n", tc + 1);
		}
		else
		{
			printf("Case #%d: NO\n", tc + 1);
		}
	}
	
	return 0;
}
