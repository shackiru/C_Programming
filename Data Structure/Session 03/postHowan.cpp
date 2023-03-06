#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tnode{
	int val;
	tnode *next;
};

	tnode *head = NULL;
	
tnode* createNode(char val){
	tnode *tmp = (tnode *)malloc(sizeof(tnode));
	tmp->val = val;
	tmp->next = NULL;
	
	return tmp;
}

void push(char val){
	tnode *tmp = createNode(val);
	if(head == NULL){
		head = tmp;
	} else{
		tmp->next = head;
		head = tmp;
	}
}

void print(){
	tnode *current = head;
	while(current){
		printf("%d ", current->val);
		current = current->next;
	}
	puts("");
}

tnode *pop(){
	if(head == NULL){
		printf("There's no data\n");
	} else{
		tnode *tmp = head->next;
		tnode *tmp2 = createNode(head->val);
		free(head);
		head = tmp;
		return tmp2;
	}
}

int main(){
	
	char a [10];
	
	while(a != 0){
		scanf("%s", &a);
//		int g = (a-'0';
		int g;
		sscanf(a, "%d", &g);
		if(g == -1){
			break;
		} else{
		if(strcmp(a, "*") == 0){
			tnode *popped = pop();
			int b = popped->val;
			popped = pop();
			int c = popped->val;
			push(b*c);
		} else if(strcmp(a, "+") == 0){
			tnode *popped = pop();
			int b = popped->val;
			popped = pop();
			int c = popped->val;
			push(b+c);
		} else if(strcmp(a, "/") == 0){
			tnode *popped = pop();
			int b = popped->val;
			popped = pop();
			int c = popped->val;
			push(c/b);
		} else if(strcmp(a, "-") == 0){
			tnode *popped = pop();
			int b = popped->val;
			popped = pop();
			int c = popped->val;
			push(c - b);
		} else{
			int b;
			sscanf(a,"%d",	&b);
			push(b);
		}
		
			print();
		}
	}
	
    return 0;
}