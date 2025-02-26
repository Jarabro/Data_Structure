#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node{
	char name[10];
	struct Node* link;
} Node;
int add(Node ** head,char * str)
{	//NODE의 주소를 저장하기위한 *node 포인터 선언!
	Node * node = (Node*)malloc(sizeof(Node)); // 새노드를 동적할당 한것임
	strcpy(node->name,str);						//새 노드에 이름에 받은 값을 넣음

	if(*head==NULL) {					//head가 null이면 호출할 노드가 없다는 뜻임
		*head = node;					//헤드에 node를 넣어
		node->link = NULL;				//node.link는 NULL값으로 그래야 다음 노드를 만들었을떄 호출주소를 넣을수 있다.
	}
	else {
		Node * current = *head;			//NODE의 주소를 저장하기위한 current 선언! 인데 current에다가 *head를 넣음 
		while(current->link!=NULL)		//current.link가 NULL값이 아닐떄동안 반복해라
		{
			current=current->link;		//current = current.link를 넣어라 (주소를 넣어라
		}
		current->link=node;
		node->link=NULL;
	}
	return 0;
}

void print(Node * head)
{
	Node * current = head;
	while(current!=NULL)
	{
		printf("%s, ",current->name);
		current=current->link;
	}
	printf("\n");
	return;
}

void clear(Node ** head)
{
	Node * current= *head;
	while(current!=NULL)
	{
		Node * link = current->link;
		free(current);
		current = link;
	}
	*head=NULL;
}

int insert(Node ** head, int index, char*str)
{
	Node * node = (Node*)malloc(sizeof(Node));
	strcpy(node->name,str);

	if(*head==NULL) {
		*head = node;
		node->link = NULL;
	}
	else if(index==0) {
		node->link = (*head)->link;
		*head = node;
	}
	else {
		Node * current = *head;
		Node * prev = NULL;
		for(int i=0; i<index; i++)
		{
			if(current==NULL) 
			{
				free(node);
				return -1;
			}
			prev = current;
			current=current->link;
		}
		node->link = prev->link;
		prev->link = node;
	}
	return 0;
}

int delete(Node ** head, int index)
{
	if(*head==NULL) {
		return -1;
	}
	else if(index==0) {
		Node * node = *head;
		*head = node->link;
		free(node);
	}
	else {
		Node * current = *head;
		Node * prev = NULL;
		for(int i=0; i<index; i++)
		{
			if(current==NULL) {
				return -1;
			}
			prev = current;
			current=current->link;
		}
		prev->link = current->link;
		free(current);
	}
	return 0;
}

int main()
{
	Node * head = NULL;

	add(&head,"Mon");
	add(&head,"Fri");
	add(&head,"Sun");
	print(head);

	insert(&head,1,"Thu");
	print(head);

	delete(&head,2);
	print(head);

	clear(&head);
	print(head);

	return 0;
}

