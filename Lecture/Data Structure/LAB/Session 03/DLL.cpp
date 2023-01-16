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

void view(Node *head)
{
    Node *curr = head;
    while(curr)
    {
        printf("%s - %d\n", curr->name, curr->age);
        curr = curr->next;
    }
}

int main()
{
    Node *head = NULL, *tail = NULL;

    pushHead(&head, &tail, createNode("Budi", 20));

    view(head);
    return 0;
}