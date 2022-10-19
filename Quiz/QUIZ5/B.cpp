#include <stdio.h>

int main()
{
	int inputCase;

	scanf("%d", &inputCase);
	
	for(int tc = 0; tc < inputCase; tc++)
	{
		int result = 0;
		int count = 1;
		int plus = 0;
		int minus = 0;
		int modulo = 0;
		
		scanf("%d %d", &plus, &minus);
		
		while(plus != 0 || minus != 0)
		{
			
		modulo = (plus % 10) + (minus % 10);
		modulo = modulo % 10;
		
		result = (modulo * count) + result;
		
		plus = plus / 10;
		minus = minus / 10;
		
		count = count * 10;
		
		}

	
		printf("Case #%d: %d\n", tc + 1, result);	
			
	}
	return 0;
}

