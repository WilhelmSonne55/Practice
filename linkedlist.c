#include<stdio.h>

typedef struct node{
	int data;
	struct node* next;
	
}Node;

Node* createNode(int data){
	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp->data = data;
	tmp->next =NULL;
	return tmp;
}

Node* insert(Node* head, Node* node, int data){ //insert next to node
	Node* tmp = createNode(data);
	
	if(node == NULL){ // insert 0st
		tmp->next = head;
		head = tmp;
	}else{
		if(node->next !=NULL){ //middle
			tmp->next = node->next ;
			node->next = tmp;
		}
		else{
			node->next = tmp; //last one
		}
	}
	return head;
}


//without return Node* head => Node** head
void insertNode(Node** head, Node* ptr, Node* node){
	
	if(ptr == NULL){
		node->next=*head;
		*head = node;
	}else{
		if(ptr->next ==NULL){
			ptr->next = node;
		}else{
			node->next = ptr->next;
			ptr->next = node;
		}
	}	
}

//without return Node* head => Node** head
void deleteNode(Node** head, Node* node){
	Node* tmp = *head; 

	if(node == *head){ //first 
		*head = node->next;
	}
	else{
		while(tmp->next != node){ //last
			tmp=tmp->next;
		
		}
		if(node->next !=NULL){ //middle
			tmp->next = node->next;
		}else{
			tmp->next =NULL; //last
		}
	}
	free(node);
}

void print(Node* head){
	Node* tmp = head;
	while(tmp->next !=NULL){
		printf("%d \n", tmp->data);
		tmp = tmp->next;
	}
	printf("%d \n\n", tmp->data);
}

void reverse(Node** head){
	Node* next = NULL;
	Node* cur = *head;
	Node* tmp = NULL;
	
	while(cur !=NULL){
		next = cur->next;
		cur->next = tmp;
		tmp = cur;
		cur = next;
	}
	*head = tmp;
}

//return Node* using Node* head
Node* reverseNode(Node* head){
	Node* tmp = NULL;
	Node* next;
	Node* cur = head;
	while(cur !=NULL){
		next = cur->next;
		cur->next = tmp;
		tmp = cur;
		cur = next;
	}
	return tmp;
}

//compare
int compareList(Node* list1, Node* list2){
	
	static int flag;
	if(list1 == NULL && list2 == NULL) //the same
		flag=1;
	else{
		if(list1 == NULL || list2 == NULL) //one of lists end
			flag=0;
		else if(list1->data != list2->data) //different
			flag=0;
		else
			compareList(list1->next, list2->next); 
	}
	return flag;
}

int main(int argc, char** argv){
	Node* list = createNode(3);
	
	list = insert(list, 0, 5);
	
	Node* a = createNode(5);
	Node* b = createNode(4);
	insertNode(&list,0,a);
	insertNode(&list,a,b);

	print(list);
	
	deleteNode(&list,a);
	print(list);
	
	/*reverse*/
	reverse(&list);
	print(list);
	
	/*reverse*/
	list = reverseNode(list);
	print(list);
	
	//compare
	Node* list2 = createNode(4);
	Node* c = createNode(5);
	Node* d = createNode(3);
	insertNode(&list2,list2,c);
	// insertNode(&list2,c,d);
	print(list2);
	printf(" %d \n",compareList(list,list2));

	return 0;
}
