#include <iostream>
#include<string.h>

using namespace::std;

class StackNode{
	public:
	int data;
	StackNode* prev;

	StackNode(int x):data(x){
		prev = 0;
	}
	StackNode():data(0){
		prev = 0;
	}
};

class StackList{
	public:
	int size = 0;
	StackNode* last;
	
	void push(int x){
		StackNode* s = new StackNode(x);
		
		if(size == 0){
			last = s;
			s->prev = 0;
			++size;
		}else{
			StackNode* tmp = last;
			last = s;
			s->prev = tmp;
			++size;
		}
	}
	
	int pop(){
		if(size != 0){
			int data = last->data;
			StackNode* tmp = last;
			last = tmp->prev;
			delete tmp;
			--size;
			return data;
		}
		else{
			std::cout<<"size = 0\n"<<std::endl;
			return 11111;
		}
	}
	
	int peek(){
		if(size!=0)
		cout<<"last node: "<<last->data<<endl;
		else
		std::cout<<"size = 0"<<endl;
	}
	
};


int main(void){

	StackList sl;
	sl.push(5);
	sl.push(6);
	sl.pop();
	sl.pop();
	sl.pop();
	sl.push(6);
	sl.peek();



   return 0;
}
