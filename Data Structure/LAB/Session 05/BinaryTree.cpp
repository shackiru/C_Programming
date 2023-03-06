#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node
{
    int value;
    Node *left, *right;
}*root;

Node *createNode(int value)
{
    Node *newNode = (Node*) malloc (sizeof(Node));
    newNode->value = value;
    newNode->left = newNode->right = NULL;;
    return;
}

Node *insertNode(Node *curr, Node *node)
{
    if(curr == NULL)
    {
        return node;
    }
    else if(node->value < curr->value)
    {
        curr->left = insertNode(curr->left, node);
    }
    else if(node->value > curr->value)
    {
        curr->right = insertNode(curr->right, node);
    }
    return curr;
}

void inOrder(Node *curr)
{
    if(curr ==NULL)
    {
        return;
    }
    inOrder(curr->left);
    printf("%d\n", curr->value);

    inOrder(curr->right);
}

void deleteNode(Node *curr, int value)
{
    if(curr == NULL)
    {
        return;
    }
    else if(value < curr->value)
    {
        deleteNode(curr->left, value);
    }
    else if(value > curr->value)
    {
        deleteNode(curr->right, value);
    }
    else
    {
        if(curr->left == NULL && curr->right == NULL)
        {
            free(curr);
            curr = NULL;
        }
        else if(curr->left == NULL)
        {
            Node *temp = curr;
            curr = curr->right;
            free(temp);
        }
        else if(curr->right == NULL)
        {
            Node *temp = curr;
            curr = curr->left;
            free(temp);
        }
        else
        {
            Node *temp = minValueNode(curr->right);
            curr->val = temp->val;
            deleteNode(curr->right, temp->val);
        }
    }
}

int main()
{
    root = insertNode(root, createNode(20));
    root = insertNode(root, createNode(19));
    root = insertNode(root, createNode(18));
    root = insertNode(root, createNode(4));
    root = insertNode(root, createNode(9));

    inOrder(root);
    return 0;
}