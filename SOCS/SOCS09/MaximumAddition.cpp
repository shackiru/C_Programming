#include <stdio.h>

int main()
{
    int testCase;
    int tSample;
    long long int fMax;

    scanf("%d", &testCase);
    for(int tc = 0; tc < testCase; tc++)
    {
        long long int arr[10005] = {0};
        arr[0] = 0; 
        scanf("%d %lld", &tSample, &fMax);
        int index = -1;
        
        for(int i = 1; i <= tSample; i++)
        {
            scanf("%lld", &arr[i]);
            arr[i] = arr[i] + arr[i - 1];
        }

        for(int j = tSample; j > 0; j--)
        {
            for(int k = 0; k <= j - 1; k++)
            {
                if(arr[j] - arr[k] <= fMax)
                {
                    if(j - k > index)
                    {
                        index = j - k;
                        break;
                    }
                    else if(j - k <= index)
                    {
                        break;
                    }
                }
            }
        }
        printf("Case #%d: %d\n", tc + 1, index);
    }
    return 0;
}
