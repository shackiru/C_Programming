#include <stdio.h>

int binarySearch(int arr[], int n, int find)
{
    int index = -1;
    int low = 0;
    int high = n - 1;
    int mid;

    while(low <= high)
    {
        mid = (low + high) / 2;
        if(arr[mid] < find)
        {
            low = mid + 1;
        }
        else 
        {
            if(find == arr[mid])
			{
                index = mid;
            }
        }
            high = mid - 1;
    }
    return index + 1;
}

int main()
{
    int sample;
    int cases;

    scanf("%d %d", &sample, &cases);
    
    int sampleAmount[sample];
    int findSample[cases];
    
    for(int tc = 0; tc < sample; tc++)
    {
        scanf("%d", &sampleAmount[tc]);
    }
    
    for(int tc = 0; tc < cases; tc++)
    {
        scanf("%d", &findSample[tc]);
    }
    
    for(int i = 0; i < cases; i++)
    {
        int index = binarySearch(sampleAmount, sample, findSample[i]);
        printf("%d\n", index);
    }

    return 0;
}
