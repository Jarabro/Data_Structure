#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct ListNode{
	struct ListNode* llink;
	char data[4];
	struct ListNode* rlink;
}listNode;

typedef struct{
	listNode* head;
}linkedList_h;

linkedList_h* createLinkedList_h(void);
void printList(linkedList_h* DL);
void insertNode(linkedList_h* DL, listNode* pre, char* x);
void deleteNode(linkedList_h* DL, listNode* old);
listNode* searchNode(linkedList_h* DL, char* x);

linkedList_h* createLinkedList_h(void){
	linkedList_h* DL;
	DL = (linkedList_h*)malloc(sizeof(linkedList_h));
	DL->head =NULL;
   return DL;
}   

void printList(linkedList_h* DL){
	listNode* p;
	printf(" DL = (");
	p = DL->head;
	while(p !=NULL){
		printf("%s", p->data);
		p = p->rlink;
		if(p != NULL)printf(", ");
	}
	printf(") \n");
}

void insertNode(linkedList_h* DL, listNode *pre, char*x){
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));
	strcpy(newNode->data, x);
	if(DL->head == NULL){
		newNode->rlink = NULL;
		newNode->llink = NULL;
		DL->head = newNode;
	}
	else{
		newNode->rlink = pre->rlink;
		pre->rlink = newNode;
		newNode->llink=pre;
		if(newNode->rlink != NULL)
			newNode->rlink->llink = newNode;
	}
}

void deleteNode(linkedList_h* DL, listNode* old){
	if(DL->head == NULL) return;
	else if(old == NULL) return;
	else{
		old->llink->rlink = old -> rlink;
		old->rlink->llink = old -> llink;
		free(old);
	}
}

listNode* searchNode(linkedList_h* DL, char *x){
	listNode *temp;
	temp = DL->head;
	while(temp!=NULL){
		if(strcmp(temp->data, x)==0) return temp;
		else temp= temp->rlink;
	}
	return temp;
}

int main()
{
	linkedList_h* DL;
	listNode *p;

	DL = createLinkedList_h();
	printf("(1) 이중 연결 리스트 생성하기! \n");
	printList(DL);

	printf("\n(2) 이중 연결 리스트에 [월] 노드 삽압하기! \n");
	insertNode(DL, NULL, "월");
	printList(DL);

	printf("\n(3) 이중 연결 리스트에 [월] 노드 뒤에 [수] 노드 삽입하기! \n");
	p = searchNode(DL, "월"); insertNode(DL, p, "수");
	printList(DL);

	printf("\n(4) 이중 연결 리스트이 [수] 노드 뒤에 [금] 노드 삽입하기! \n");
	p = searchNode(DL, "수"); insertNode(DL, p, "금");
	printList(DL);

	printf("\n(5) 이중 연결 리스트에서 [수] 노드 삭제하기! \n");
	p = searchNode(DL, "수"); deleteNode(DL, p);
	printList(DL);

	getchar();	return 0;
}
