#include <stdio.h>

int main()
{
	int input;
	int room;
	int roomCount;
	int roomTotal = 0;
	int counter = 0;
	int array[5005] = {};
	
	scanf("%d", &input);
	for(int tc = 1; tc <= input; tc++)
	{
		scanf("%d", &room);
		
		roomCount = 0;
		for(int i = 0; i < counter; i++)
		{
			if(array[i] == room)
			{
				roomCount++;
				break;
			}
		}
		if(roomCount == 0)
		{
			roomTotal++;
			array[counter] = room;
			counter++;
		}
	}
	printf("%d\n", roomTotal);
	
	return 0;
}

