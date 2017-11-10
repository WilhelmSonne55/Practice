#include<stdio.h>

typedef struct node{
	int data;
	struct Node* next;
}Node;

Node* createNode(int data){
	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp->data = data;
	tmp->next = NULL;
	return tmp;
}

void push(Node** top, Node* node){
	if(*top !=NULL){
		Node* tmp;
		tmp = *top;
		*top = node;
		node->next = tmp;
	}
	else{
		*top=node;
	}

}

void pop(Node** top){
	Node* tmp;
	tmp = (*top)->next;
	free(*top);
	*top = tmp;
}

void print(Node* top){
	Node* tmp = top;
	if(tmp!=NULL){
		while(tmp->next != NULL){
		printf(" %d \n", tmp->data);
		tmp=tmp->next;
		}
		printf(" %d \n\n", tmp->data);	
	}
	else
		printf("without node in stack\n");
}

int main(int argc, char** argv){
	
	Node* top = createNode(1);
	Node* a = createNode(2);
	Node* b = createNode(3);
	push(&top,a);
	print(top);
	
	pop(&top);
	print(top);

	pop(&top);
	push(&top,b);
	print(top);
	
	return 0;
}
