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

// void insertRef()
// {
//     struct doc * newDoc  = (struct doc*) malloc(sizeof(doc));
//     newDoc->page = page;
//     if(headDoc == NULL) {
//         newDoc->next = NULL;
//         headDoc = newDoc; 
//     } 
//     else 
//     {
//         struct doc* iter = headDoc;
//         while(iter->next) {
//             iter = iter->next;
//         }
//         iter->next = newDoc;
//     }
// }

void insertNode(char s[], doc* docPos)
{
    // int check = 1;
    struct node * newNode = (struct node*) malloc (sizeof(node));
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
        while(iter->next != NULL && strcmp(iter->string, newNode->string) != 0)
        {
            iter = iter->next;
        }
        if(strcmp(iter->string, newNode->string) == 0){
             //cek doc
            struct doc *iterRef = iter->ref;
            while(iterRef->next != NULL && iterRef->page != newNode->ref->page){
                iterRef = iterRef->next;
            }
            struct doc * newDoc  = (struct doc*) malloc(sizeof(doc));
            newDoc->page = page;
            iterRef->next = newDoc;

            // iter = hashTable[key];
            // while(iter){
            //     if(iter->ref == newNode->ref && strcmp(iter->string, newNode->string) == 0) {
            //         check = 0;
            //         break;
            //     }
            // }
        }
        // if(check == 1){
        //     iter->next = newNode;
        // }
    }
    
}

void indexSentence(char s[])
{
    strtok(s, " ");
    while(s != NULL)
    {
        //insertDoc(s);
        // insertNode(s, docPos);
        //panggil function indexing(?)
        s = strtok(NULL, " ");
        insertNode(s);
    }
}
    
void readFile()
{
    FILE *f = fopen("CaseShift2.csv", "r");
    char words[5005];
    while(!feof(f))
    {
        fscanf(f, "%[^\n]", words);
        fgetc(f);
        //function index per kata
        // struct doc* tmp = insertDoc();
        indexSentence(words);
        page++;
        // printf("%s\n", words);        
    }
}


void printFile() 
{
    for (int i = 0; i < MAX; i++){
        if (hashTable[i] != NULL){
            // printf("Synopsis Found!\n");
            printf("%d -> ", i);
            struct node *iter = hashTable[i];
            while(iter)
            {
                printf("%s ", iter->string);
                iter = iter->next;
            }
            printf("\n");
        }
        else
        {
            printf("NULL\n");
        }
    }
    
}

int main()
{
    // char search[];
    // while (true){
        // scanf("%s", search);
        readFile();

        printFile();
        
        
    // }
    

    return 0;
}