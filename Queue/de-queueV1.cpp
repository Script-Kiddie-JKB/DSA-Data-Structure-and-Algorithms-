#include<iostream>
using namespace std;
int SIZE;
class dequeue 
{
	 int arr[30],front,rear;  //private default
	 public:
	 dequeue();
	 void insert_at_beg(int);
	 void insert_at_end(int);
	 void delete_fr_front();
	 void delete_fr_rear();
	 void display_queue();
};
dequeue::dequeue() 
{
 front=-1;
 rear=-1;
}
	void dequeue::insert_at_end(int i) 
{
 if(rear>=SIZE-1) 
 {
 	cout<<"\nInsertion of data not possible, Overflow!!!!";
 } 
 
    else 
 {
 		if(front==-1)
   	{
 		front++;
 		rear++;
  	}
	else 
	{
 		rear=rear+1;
 	}
 		arr[rear]=i;
 		cout<<"\nYour Inserted Element is : "<<arr[rear];
 }
}
void dequeue::insert_at_beg(int i) 
{
 		if(front==-1) 
 	{
		front=0;
 		arr[++rear]=i;
 		cout<<"\nYour Inserted Element is : "<<i;
 	} 	
	 	else if(front!=0) 
 	{
 		arr[--front]=i;
 		cout<<"\nYour Inserted Element is : "<<i;
 	} else 
 {
 cout<<"\nInsertion of element not possible, overflow!!!";
 }
}
void dequeue::delete_fr_front() 
	{	
 		if(front==-1) 
 	{
 		cout<<"\nDeletion is not possible ---> dequeue is empty";
 		return;
 	}
 		else 
 	{
 		cout<<"\nThe deleted element is :"<<arr[front];
 		if(front==rear) 
 	{
 		front=rear=-1;
 		return;
	} 
		else
 		front=front+1;
 	}
	}
 void dequeue::delete_fr_rear() 
 	{
 		if(front==-1) 
 		{
 			cout<<"Deletion is not possible ---> Dequeue is empty";
 			return;
 		}
			else 
 		{
			cout<<"\nThe deleted element is : "<<arr[rear];
 			if(front==rear) 
 			{
 				front=rear=-1;
			}
			 else
 				rear=rear-1;
 		}
 	}	
 void dequeue::display_queue() 
 	{
 			if(front==-1) 
 		{
 			cout<<"\nDouble ended queue is empty";
 		}
		 	 else 
 			{
 				for(int i=front;i<=rear;i++) 
 				{
 					cout<<arr[i]<<" ";
	 			}
 			}
 	}
int main() 
{
 int choice,i;
 cout<<"\nEnter Size of Queue to Perform Operations : ";
 cin>>SIZE;
 dequeue d;
 do 				//perform switch opeartion
 {
 cout<<"\n\n*********** MAIN-MENU ************";
 cout<<"\n 1.Insert element at BEGINNING";
 cout<<"\n 2.Insert element at END";
 cout<<"\n 3.Display [Print All Elements Availabe in Queue]";
 cout<<"\n 4.Deletion of element from FRONT";
 cout<<"\n 5.Deletion of element from REAR";
 cout<<"\n 6.exit";
 cout<<"\n 7.Clear Screen";
 cout<<"\n\n Enter your choice : ";
 cin>>choice;
 switch(choice) 
 {
 case 1:
	 cout<<"\nEnter your element to be inserted in Beginning of Queue : ";
 	 cin>>i;
 	 d.insert_at_beg(i);
 break;
 case 2:
 	 cout<<"Enter your element to be inserted in End of Queue : ";
 	cin>>i;
 	 d.insert_at_end(i);
 break;
 case 3:
 	 d.display_queue();
 break;
 case 4:
 	 d.delete_fr_front();
 break;
 case 5:
 	 d.delete_fr_rear();
 break;
 case 6:
 	 exit(0);
 break;
 case 7:
	system("cls");
	break;
 default:
 	 cout<<"\n----Invalid choice----";
 break;
 }
 } while(choice!=6);
}

