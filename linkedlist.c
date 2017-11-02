#include<stdio.h>
#include<stdlib.h>

struct node{
	struct node* next;
	int data;
	node(){
		data= 0;
		next = NULL;
	}

};


struct linklist{
	struct node* last;
	struct node* first;
	int size = 0;
	
	/*push into the middle of link list  */
	void push(int n, int data){
		
		if(n > size){	//check if n > actual linklist size
			printf("out of the size of the link list\n");
		}
		else{
			struct node* tmp = (struct node*)malloc(sizeof(struct node));
			tmp->data = data;
			tmp->next = NULL;
				
			if(0 < size){	//if size=1 first=last, else....
				struct node* tmp2 = first;
				++size;

				if(size == 2){	//if size=2, last must the new one
					tmp->next = tmp2->next;
					tmp2->next = tmp;
					last = tmp;
					
				}else{	//last might be the new one's next
					int i = 1;	//i : size 1. 2. 3. 4.....not from 0
					while(tmp2->next !=NULL){
						if(i == n){
							tmp->next= tmp2->next;
							tmp2->next = tmp;
						}												
						tmp2 = tmp2->next;
						last = tmp2;
						++i;
					}
				}	
			}
			else{
				++size;
				first = tmp;
				last = tmp;
			}	
		}	
		
		printAll();
	}
	
	void printAll(){
		struct node* tmp = first;
		int i=0;
		printf("\n size:%d :",size);
		while(i < size){
			printf(" %d ", tmp->data);
			tmp = tmp->next;
			++i;
		}
		
	}
	
	
	
};


int main(int argc, char*argv[]){
	struct linklist link;
	//link.push(0,5);
	link.push(0,6);
	link.push(1,5);
	link.push(1,9);
	// link.push(3,8);

	// printf(" %d \n",link.last->data);
	// printf(" %d ",link.size);
	//link.printAll();
	
	
	
	return 0;
}
