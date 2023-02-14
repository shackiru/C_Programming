#include<stdio.h>
#include<stdlib.h>


struct node{
	int angka;
	node* prev;
	node* next;
};

node* head = NULL;
node* tail = NULL;

struct node* create(int x){
	node* temp = (node*) malloc(sizeof(node));
	temp->angka = x;
	temp->next = NULL;
	temp->prev = NULL;
	return temp;
}

void insertFront(){
	int input;
	printf("Input number: ");
	scanf("%d",&input);
	
	if(head==NULL && tail==NULL){
		head=tail=create(input);
	}
	else{
		node* ptr = create(input);
		head->prev = ptr;
		ptr->next = head;
		head = ptr;
	}
	return;	
}

void insertLast(){
	int input;
	printf("Input number: ");
	scanf("%d",&input);
	if(head==NULL && tail==NULL){
		head=tail=create(input);
	}
	else{
		node* ptr = create(input);
		ptr->prev = tail;
		tail->next = ptr;
		tail = ptr;
	}
	return;	
}

void insertMiddle(){
	int count=0;
	node* iter = head;
	while(iter!=NULL){
//		printf("%d ",iter->angka);
		iter = iter->next;
		count++;
	}
	int input;
	
	if(count<2){
		printf("Cannot insert between two numbers\n");
		return;
 	}
 
	do{
		printf("Input after i-th number [1-%d]: ",count-1);
		scanf("%d",&input);
	} while(input<1 || input>(count-1));
	
	printf("Input number: ");
	int z;
	scanf("%d",&z);
	
	iter = head;
	int count2=0;
	while(count2<input-1){
		iter = iter->next;
		count2++;
	}
	node* ptr = create(z);
	ptr->prev = iter;
	ptr->next = iter->next;
	iter->next->prev = ptr;
	iter->next = ptr;
	
	return;	
}

void printFromHead(){
	node* iter = head;
	while(iter!=NULL){
		printf("%d ",iter->angka);
		iter = iter->next;
	}
	printf("\n");
	return;	
}

void printFromTail(){
	node* iter = tail;
	while(iter!=NULL){
		printf("%d ",iter->angka);
		iter = iter->prev;
	}
	printf("\n");
	return;	
}

void deleteFirst(){
//	node* temp = head->next;
//	head->next = NULL;
//	head->prev = NULL;
//	free(head);
//	head = temp;
//	head->prev = NULL;
	node* temp = head;
	head = head->next;
	head->prev = NULL;
	free(temp);
	printf("Data successfully deleted. Press enter to continue..."); getchar();
	return;	
}

void deleteLast(){
	node* temp = tail->prev;
	tail->prev = NULL;
	tail->next = NULL;
	free(tail);
	tail = temp;
	tail->next = NULL;
	return;	
}

void deleteMiddle(){
	int count=0;
	node* iter = head;
	while(iter!=NULL){
//		printf("%d ",iter->angka);
		iter = iter->next;
		count++;
	}
	int input;
	
	if(count<3){
		printf("Cannot delete between two numbers\n");
		return;
 	}
 
	do{
		printf("Delete i-th number [2-%d]: ",count-1);
		scanf("%d",&input);
	} while(input<2 || input>(count-1));
	
	iter = head;
	int count2=0;
	while(count2<input-1){
		iter = iter->next;
		count2++;
	}
	node* iterDel = iter;
	iter->next->prev = iter->prev;
	iter->prev->next = iter->next;
	free(iterDel);
	
	return;	
}

void menu(){
	while(true){
		printf("||Double Linked List Menu||\n"
				"1. Insert Front\n"	
				"2. Insert Last\n"
				"3. Insert Middle\n"
				"4. Print From Head\n"
				"5. Print From Tail\n"
				"6. Delete First Element\n"
				"7. Delete Last Element\n"
				"8. Delete Element Between First and Last\n"
				"Input: "
		);
		int input;
		scanf("%d",&input); getchar();
		if(input==1){
			insertFront();
		}
		if(input==2){
			insertLast();
		}
		if(input==3){
			insertMiddle();
		}
		if(input==4){
			printFromHead();
		}
		if(input==5){
			printFromTail();
		}
		if(input==6){
			deleteFirst();
		}
		if(input==7){
			deleteLast();
		}
		if(input==8){
			deleteMiddle();
		}
		if(input<1 || input>8){
			printf("Invalid Input!\n");
		}
	
	}
}

int main(){
	menu();
	return 0;
}