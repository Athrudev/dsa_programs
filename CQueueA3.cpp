#include <iostream> 
using namespace std; 
int n=5; 
int q[5]; 
int front = -1 ; 
int rear = -1 ;
void enqueue()
{ 
 int item;
 if((front==0 && rear==n-1) || (rear==front-1))
 {
 	cout<<"\nOVERFLOW";
 }
 else
	{
		 cout<<"\nEnter the element to insert in Q ";
		 cin>>item;
		 if(rear==-1) //initially empty
		 front=rear=0;
		 else
		 if(rear==n-1)
		 rear=0;
		 else
		 rear++;
		 q[rear]=item;
		 cout<<item<<" is inserted in Q\n";	 
	} 
}
void dequeue()
{
 int item;
 if(front==-1)
 {
 cout<<"\nUNDERFLOW";
 }else
 {
 item = q[front];
 cout<<item<<" is deleted from Q\n";
 if(front==rear) // Q contains single element
 {
 front=rear=-1;
 }
 else
 if(front==n-1)
 front=0;
 else
 front++;
 }
}
void display()
{
 int i;
 if(front==-1)
 cout<<"\nQ is empty";
 else
 {
 if(front<=rear)
 {
 for(i=front;i<=rear;i++)
 cout<<q[i]<<"\t";
 }
 else
 {
 for(i=front;i<=n-1;i++)
 cout<<q[i]<<"\t";
 for(i=0;i<=rear;i++)
 cout<<q[i]<<"\t";
 }
 }
}
int main()
{
 int ch;
 do
 {
 cout<<"\n\nMENU";
 cout<<"\n1 Insert\n2 Delete\n3 Display\n4 Exit";
 cout<<"\nChoice ? ";
 cin>>ch;
 switch(ch)
 {
 case 1: enqueue(); break;
 case 2: dequeue(); break;
 case 3: display(); break;
 case 4: break;
 default:cout<<"\nWrong Choice ";
 }
 }while(ch!=4);
 cout<<"\nThank You:";
 return 0;
}