#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node
{
    char name[100];
    int age;
    Node *next, *prev;
};

Node *createNode(const char *name, const int age)
{
    Node *node = (struct Node*) malloc (sizeof(Node));
    strcpy(node->name, name);
    node->age = age;
    node->next = node->prev = NULL;
    return node;
}

void pushHead(Node **head, Node **tail, Node *node)
{
    if(*head == NULL)
    {
        *head = *tail = node;
    }
    else
    {
        node->next = *head;
        (*head)->prev = node;
        *head = node;
    }
}

void pushTail(Node **head, Node **tail, Node *node)
{
    if(*head == NULL)
    {
        *head = *tail = node;
    }
    else
    (*tail)->next = node;
    node->prev = *tail;
    *tail = node;
}

void pushValue(Node **head, Node **tail, Node *node)
{
    if(*head == NULL || strcmp(node->name, (*head)->name) < 0)
    {
        pushHead(head, tail, node);
    }
    else if(strcmp(node->name, (*tail)->name) >= 0)
    {
        pushTail(head, tail, node);
    }
    else
    {
        Node *curr = *head;
        while(strcmp(node->name, curr->next->name) > 0)
        {
            curr = curr->next;
        }
        node->next = curr->next;
        curr->next->prev = node;
        node->prev = curr;
        curr->next = node;
    }
}

void view(Node *head)
{
    Node *curr = head;
    while(curr)
    {
        printf("%s - %d\n", curr->name, curr->age);
        curr = curr->next;
    }
}

void popHead(Node **head, Node **tail)
{
    if(*head == NULL)
    {
        return;
    }
    else if(*head == *tail)
    {
        free(*head);
        *head = *tail = NULL;
    }
    else
    {
        Node *temp = *head;
        *head = (*head)->next;
        free(temp);
        temp = NULL;
        (*head)->prev = NULL;

        *head = (*head)->next;
        free((*head)->prev);
        (*head)->prev = NULL;
    }
}

void popTail(Node **head, Node **tail)
{
    if(*head == NULL)
    {
        return;
    }
    else if(*head == *tail)
    {
        free(*head);
        *head = *tail = NULL;
    }
    else
    {

    }
}

int main()
{
    Node *head = NULL, *tail = NULL;

    //pushHead(&head, &tail, createNode("Budi", 20));
    //pushTail(&head, &tail, createNode("Shaq", 19));
    printf("Before:\n");
    pushValue(&head, &tail, createNode("Dexter", 20));
    pushValue(&head, &tail, createNode("Budi", 20));
    pushValue(&head, &tail, createNode("Jordy", 20));
    pushValue(&head, &tail, createNode("Shaq", 20));
    pushValue(&head, &tail, createNode("Fredoy", 20));
    view(head);
    printf("\n");

    printf("After:\n");
    popHead(&head, &tail);
    view(head);
    printf("\n");
    
    return 0;
}