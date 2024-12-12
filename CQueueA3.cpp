#include<iostream>
using namespace std;

struct Node{
	int data;
	Node* next;
};

class CircularQueue{
	Node* front;
	Node* rear;

public:
	CircularQueue(){
		front=nullptr;
		rear=nullptr;
	}


	void enque(){
		int val;

		cout<<"Enter the value:";
		cin>>val;

		Node* newNode=new Node{val,nullptr};

		if(rear==nullptr){
			front=newNode;
			rear=newNode;
			rear->next=front;
		}else{
			rear->next=newNode;
			rear=newNode;
			rear->next=front;
		}
	}


	void deque(){

		int val;

		if(front==rear){
			val=front->data;
			delete front;
			front=rear=nullptr;
		}else{
			Node* temp=front;
			val=temp->data;
			front=front->next;
			rear->next=front;
			delete temp;
		}

		cout<<"\nDeleted element:"<<val;

	}


	void display(){
		if(front==nullptr){
			cout<<"Queue is Empty";
			return;
		}

		Node* temp=front;
		do{
			cout<<temp->data<<",";
			temp=temp->next;
		}while(temp!=front);
	}

};

int main(){

	int ch;
	bool loop=true;

	CircularQueue c;
	while(loop){
	cout<<"\n\n1.Enque\n2.Deque\n3.Display\n4.Delete";
	cout<<"\nEnter Your choice:";
	cin>>ch;
	

		switch(ch){
			case 1:
			c.enque();
			break;

			case 2:
			c.deque();
			break;

			case 3:
			c.display();
			break;

			case 4:
			loop=false;
			cout<<"Exited Successfully";
			break;

			default:
			cout<<"Invalid choice";

		}

	}
	


	return 0;
}