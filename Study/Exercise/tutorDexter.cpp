#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Doc
{

};

int hashing(char s[])
{
    if(s[0] >= 'A' && s[0] <= 'Z')
    {
        return s[0] - 'A';
    }
    else if(s[0] >= 'a' && s[0] <= 'z')
    {
        return s[0] - 'a';
    }
}

void input(char *s, int page)
{
    int key = hashing(s);
    if(hashTable[key] == NULL)
    {
        hashTable[key] = createNode(s, page);
        return;
    }
}

void readFile()
{
    FILE *f = fopen("CaseShift2.csv", "r");
    char temp[50000] = {0};
    int i = 0;
    while(feof(f) == NULL)
    {
        i++;
        fscanf(f, "%[^\n]\n", temp);
        char *token = strtok(temp, ",");
        token = strtok(temp, " ");
        while (token != NULL)
        {
            input(token, i);
            token = strtok(NULL, " ");
        }
    }
}

void searchData()
{

}