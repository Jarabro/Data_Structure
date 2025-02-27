#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef int element;
typedef struct stackNode{
	element data;				//int data이다.
	struct stackNode * link;
}stackNode;

stackNode * top;

int isStackEmpty();
void push(element item);
element pop();
element peek();
void printStack();

int isStackEmpty(){
	if(top==NULL) return 1;
	else return 0;
}

void push(element item){
	stackNode *temp = (stackNode*)malloc(sizeof(stackNode));

	temp->data = item;
		temp->link = top;
		top = temp;
}

element pop(){
	element item;
	stackNode * temp = top;

	if(isStackEmpty()){
		printf("\n\n Stack is empty !\n");
		return 0;
	}
	else{
		item = temp->data;
		top = temp->link;
		free(temp);
		return item;
	}
}

element peek(){
	if(isStackEmpty()){
		printf("\n\n Stack is empty !\n");
		return 0;
	}
	else{
		return(top->data);
	}
}

void printStack(){
	stackNode* p = top;
	printf("STACK [ ");
	while(p){
		printf("%d ", p->data);
		p = p->link;
	}
	printf("] ");
}

int main()
{
	element item;							//int item; 이랑 같음
	top = NULL;								//
	printf("\n** 연결 스택 연산 **\n");
	printStack();

	push(1);	printStack();
	push(2);	printStack();
	push(3);	printStack();

	item = peek(); printStack();
	printf("peek => %d ", item);

	item = pop(); printStack();
	printf("\t pop => %d ", item);

	item = pop(); printStack();
	printf("\t pop => %d ", item);

	item = pop(); printStack();
	printf("\t pop => %d ", item);

	getchar(); return 0;
}
