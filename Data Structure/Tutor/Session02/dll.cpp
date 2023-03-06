#include<stdio.h>
#include<stdlib.h>

struct tNode
{
	//menyimpan data
	int value;
	//menyimpan address setelahnya
	struct tNode* next;
};

struct tNode* head = NULL;
struct tNode* tail = NULL;

struct tNode* initNode(int x)
{
	struct tNode* ptr = new tNode;
	ptr->value = x;
	ptr->next = NULL;
	return ptr;
}

void insertFront(int x)
{
	struct tNode* ptr = initNode(x);
	ptr->next = head;
	head = ptr;
	
	return;
}

void insertBack(int x)
{
	// tNode* tmp = head;
	// while(tmp->next!=NULL)
    // {
	// 	tmp=tmp->next;
	// }
	
	tNode* var = initNode(x);
	// tmp->next = var;              
	// var->next = NULL;
    tail->next = var;
    tail = var;
	
	return;
}

void insertSorted(int x)
{
    if(x < head->value)
    {
        insertFront(x);
    }
    else if(x > tail->value)
    {
        insertBack(x);
    }
    else
    {
        struct tNode *iter = head;
        while(iter->next->value < x)
        {
            iter = iter->next;
        }
        printf("Data iter: %d\n", iter->value);
        struct tNode *node = initNode(x);
        node->next = iter->next;
        iter->next = node;
    }
}

void printList()
{
	tNode* iter = head;
	while(iter!=NULL)
    {
		printf("%d\n",iter->value);
		iter = iter->next;
	}
	return;
}


void deleted(int x)
{
    if(head && head->value == x && !head->next)
    {
        // element satu satunya
        free(head);
    }
    else if(head->value == x)
    {
        // delete element paling depan
        struct tNode *iterDel = head;
        head = head->next;
        iterDel->next = NULL;
        free(iterDel);
    }
    else
    {
        struct tNode *iter = head;
        while(iter->next && iter->value != x)
        {
            iter = iter->next;
        }
        printf("element: %d\n", iter->value);
        struct tNode *iterDel = iter->next;
        iter->next = iter->next->next;
        free(iterDel);
    }
}

int	main(){
	head = initNode(19);
	insertFront(30);
    insertBack(8);
    printf("Before Delete\n");
    printList();
    printf("After Delete\n");
    deleted(30);
    printList();
    insertSorted(41);

		
	
	
	return 0;
}
