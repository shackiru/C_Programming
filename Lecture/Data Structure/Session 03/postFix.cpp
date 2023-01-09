#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct node
{
    int value;
    struct node * next;
};

struct node * stack = NULL;

void printStack()
{
    struct node * iter = stack;
    while(iter != NULL)
    {
        printf("%d ", iter->value);
        iter = iter->next;
    }
}

struct node * createNode(int val)
{
    struct node * temp = (struct node*) malloc (sizeof(struct node));
    temp->value = val;
    temp->next = NULL;
}

void push(int val)
{
    struct node * temp = createNode(val);
    temp->next = stack;
    stack = temp;
}

int pop()
{
    struct node * temp = stack;
    int val = temp->value;
    stack = temp->next;
    free(temp);
    return val;
}

int main()
{
    //variable to storage input notation
    char s[100];
    scanf("%s", s);

    int i = 1;
    stack = createNode(s[0] - '0');
    //create stack from first character
    int final = 0;
    while(s[i])
    {
        // push if digit
        if(isdigit(s[i]))
        {
            push(s[i] - '0');
        }
        // pop and push if operator
        else
        {
            int a = pop();
            int b = pop();
            int x;
            switch(s[i])
            {
                case '*':
                {
                    x = b * a;
                    push(x);
                    break;
                }
                case '+':
                {
                    x = b + a;
                    push(x);
                    break;
                }
                case '/':
                {
                    x = b / a;
                    push(x);
                    break;
                }
                case '-':
                {
                    x = b - a;
                    push(x);
                    break;
                }
                default:
                {
                    break;
                }
            }
            i++;
        }
    }
    final = pop();
    printf("%d ", final);
    
    return 0;
}