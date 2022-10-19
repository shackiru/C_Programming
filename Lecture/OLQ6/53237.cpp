#include <stdio.h>
#include <string.h>

int main()
{
    char word[10005];
    gets(word);

    int len = strlen(word);
	
    for(int i = 0; i < len; i++)
    {
        if('a' <= word[i] && word[i] <= 'z')
        {
            word[i] = word[i] + 'A' - 'a';
        }
        switch(word[i])
        {
            case 'I' :
                word[i] = '1';
                break;
                
            case 'R' :
                word[i] = '2';
                break;
                
            case 'E' :
                word[i] = '3';
                break;
                
            case 'A' :
                word[i] = '4';
                break;
                
            case 'S' :
                word[i] = '5';
                break;
                
            case 'G' :
                word[i] = '6';
                break;
                
            case 'T' :
                word[i] = '7';
                break;
                
            case 'B' :
                word[i] = '8';
                break;
                
            case 'P' :
                word[i] = '9';
                break;
                
                
            case 'O' :
                word[i] = '0';
                break;
                
        }
    }
    printf("%s\n", word);
    return 0;
}
