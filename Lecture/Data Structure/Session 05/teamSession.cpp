#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 26

struct node 
{
    char string[50];
    struct node* next;
    struct doc* ref;
} * hashTable[MAX]; 

struct doc 
{
    int page;
    struct doc* next;
};

void initTable()
{
    for(int i = 0; i < 26; i++)
    {
        hashTable[i] = NULL;
    }
}

struct doc *headDoc = NULL; 
int page = 1;

int hashing(char s[])
{
    return s[0] - 'a';
}

void insertDoc()
{
    struct doc * newDoc  = (struct doc*) malloc(sizeof(doc));
    newDoc->page = page;
    if(headDoc == NULL) {
        newDoc->next = NULL;
        headDoc = newDoc; 
    } 
    else 
    {
        struct doc* iter = headDoc;
        while(iter->next) {
            iter = iter->next;
        }
        iter->next = newDoc;
    }
}

void insertNode(char s[])
{
    struct node * newNode = (struct node*) malloc(sizeof(node));
    strcpy(newNode->string, s);
    newNode->next = NULL;
    newNode->ref = NULL;
    int key = hashing(s) % MAX;
    if(hashTable[key] == NULL)
    {
        hashTable[key] = newNode;
    }
    else
    {
        struct node *iter = hashTable[key];
        while(iter->next != NULL)
        {
            iter = iter->next;
        }
        iter->next = newNode;
    }
}

void indexSentence(char s[])
{
    strtok(s, " ");
    while(s != NULL)
    {
        //insertDoc(s);
        s = strtok(NULL, " ");
        //panggil function indexing(?)
        insertNode(s);
    }
} 


void readFile()
{
    FILE *f = fopen("CaseShift2.csv", "r");
    char words[5005];
    char c;
    while(!feof(f))
    {
        fscanf(f, "%[^\n]", words);
        fgetc(f);
        //function index per kata
        insertDoc();
        page++;
        // printf("%s\n", words);        
    }
}


void printFile() 
{
    
}

int main()
{
    /*char search[];
    while (true){
        scanf("%s", search);
        readFile();

        printFile();
        
        
    }
    */
    
    readFile();
    

    return 0;
}