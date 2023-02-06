#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tnode
{
    char c;
    struct tnode *left;
    struct tnode *right;
};

char s[100] = {0};
int p = 0;

struct tnode * newNode(char c)
{
    struct tnode *temp =(struct tnode *) malloc (sizeof(struct tnode));
    temp->c = c;
    temp->left = temp->right = NULL;
    return temp;
}

int isOperator(char c)
{
    char op[] = "%*-^+/";
    if(strchr(op, c))
    {
        return 1;
    }
    return 0;
}

void insert(struct tnode * curr)
{
    if(isOperator(s[p]))
    {
        p++;
        curr->left = newNode(s[p]);
        insert(curr->left);

        p++;
        curr->right = newNode(s[p]);
        insert(curr->right);
    }
}

void prefix(struct tnode *curr)
{
    printf("%c ", curr->c);
    if(curr->left != NULL)
    {
        prefix(curr->left);
    }
    if(curr->right != NULL)
    {
        prefix(curr->right);
    }
}

void postfix(struct tnode *curr)
{
    if(curr->left != NULL)
    {
        postfix(curr->left);
    }
    if(curr->right != NULL)
    {
        postfix(curr->right);
    }
    printf("%c ", curr->c);
}

void postfix(struct tnode *curr)
{
    if(isOperator(curr->c))
    {
        printf("(");
    }
    if(curr->left != NULL)
    {
        postfix(curr->left);
    }
    printf("%c ", curr->c);
    if(curr->right != NULL)
    {
        postfix(curr->right);
    }
    if(isOperator(curr->c))
    {
        printf(")");
    }
}


int main()
{
    scanf("%s", s);
    struct tnode *root = newNode(s[0]);
    insert(root);
    prefix(root);
    printf("\n");
    postfix(root);
    infix(root);
    return 0;
}
