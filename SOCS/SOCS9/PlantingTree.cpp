#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int testCase;
    int numName;
    char name[105][105];
    char plant[105][105];
    char findName[105];

    FILE *f = fopen("testdata.in", "r");
    	fscanf(f, "%d", &testCase); 
		fgetc(f);
        for(int tc = 0; tc < testCase; tc++)
        {
            fscanf(f,"%[^#]#%[^\n]", &name[tc], &plant[tc]);
            fgetc(f);
        }

        fscanf(f, "%d", &numName);
        for(int i = 0; i < numName; i++)
        {
            fscanf(f, "%s", findName);
            fgetc(f);
            
            printf("Case #%d: ", i + 1);
            int flag = 0;
            for(int j = 0; j < testCase; j++)
            {
//            	printf("name %s Findname %s\n",name[j],findName);
//            	printf("%d\n",strcmp(name[j], findName));
                if(strcmp(name[j], findName) == 0)
                {
                    printf("%s\n", plant[j]);
                    break;
                }
                flag++;
                }
                if(flag == testCase)
                {
                    printf("N/A\n");
                }
            }
    fclose(f);
    return 0;
}

