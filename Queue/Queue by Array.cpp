#include <iostream>

using namespace std;
 
// Global declaration of variables
int n;
int queue[10];     		  // Array implementation of queue
int front, rear;  		 // To insert and delete the data elements in the queue respectively
int i;             		// To traverse the loop to while displaying the stack
int choice;        		// To choose either of the 3 queue operations

void insert(); 			// Function for insert an element into the queue
void del(); 			// Function for delete an element from the queue
void display(); 		// Function for display all the elements in the queue according to FIFO 
 
int main()
{

			cout<<"\nEnter Size of Queue to Perform Operations : ";
			cin>>n;

			front = rear = -1; // Initializing front and rear to -1 indicates which means it is empty
			do
{
            cout<<"\n\n****** MAIN-MENU ******";                                                                                                                                                                                             
			cout<<"\n1. Insertion "<<endl;
        	cout<<"2. Deletion "<<endl;
        	cout<<"3. Display "<<endl;
        	cout<<"4. Exit "<<endl;
        	cout<<"5. For Clear Screen"<<endl;
			cout<<"\n\nEnter your choice: ";
			cin>>choice;
 
			switch(choice)
					{
						case 1:
								insert();
								break;
						case 2:
								del();
								break;
						case 3:
								display();
								break;
						case 4:
								break;
						case 5:
								system("cls");
								break;
						default:
								cout<<"Sorry, Invalid choice! Select From above Choices..\n";
								break;
					}
				} while(choice!=4);
return 0; 
}

				void insert()
					{
							int Value;
							if (rear == n - 1)
							cout<<"\n## Queue Reached Max of Your Entered Queue Size!!";
							else
							{
								if (front == - 1)
								front = 0;
								cout<<"\nEnter the Value to be inserted in the queue: ";
								cin>>Value;
								rear++;
								queue[rear] = Value;
							}
					} 

					void del()
					{
							if (front == - 1 || front > rear)   //if front is empty or front > rear coz rear++ happens
						{
							cout<<"\nQueue underflow (EMPTY..!)";
						}
							else
						{
							cout<<"\nThe deleted Value from the queue is: "<< queue[front]<<endl;
							front++;
						}
					} 

					void display()
					{
						int i;
						if (front > rear || front == - 1)  
						{
							cout<<"\nNo Values to Display (EMPTY..!)";
						}
							else
						{
							cout<<"\nThe Values of the queue are:"<<endl;
							for (i = front; i <= rear; i++)
							cout<< queue[i] <<endl;
						}
					}
