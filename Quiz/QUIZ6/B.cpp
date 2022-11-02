#include <stdio.h>

int main()
{
	int n;
	long long int a, b, c = 0;
	int index;
	
	scanf("%d", &n);
	
	for(int tc = 0; tc < n; tc++)
	{
		scanf("%d %lld %lld", &index, &a, &b);
		
		if(index == 0)
		{
			printf("Case #%d: %lld\n",tc +  1, a);
		}
		else if(index == 1)
		{
			printf("Case #%d: %lld\n",tc +  1, b);
		}
		else
		{
			for(int i = 1; i < index; i++)
			{
				c = b - a;
				a = b;
				b = c;	
			}
			printf("Case #%d: %lld\n",tc +  1, c);	
		}
	}
	
	return 0;
}
