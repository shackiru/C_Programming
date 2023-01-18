#include <stdio.h>
#include <string.h>


int hashFunc(char value[])
{
    return value[0] - 'a';
}

char hashTable[26][26];
void initTable()
{
    for(int i = 0; i < 26; i++)
    {
        strcpy(hashTable[i], "");
    }
}

void printTable()
{
    for(int i = 0; i < 26; i++)
    {
        if(hashTable[i][0] != '\0')
        {

        }
    }
}

int main()
{
    char s[26]; 
    int key = 0;
    
    scanf("%s", s);
    key = hashFunc(s);
    strcpy(hashTable[key], s);

    scanf("%s", s);
    key = hashFunc(s);
    strcpy(hashTable[key], s);
    return 0;
}