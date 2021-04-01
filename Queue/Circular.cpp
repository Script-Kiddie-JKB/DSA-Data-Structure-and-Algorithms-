#include <iostream>
using namespace std;
int size;
 
class circular_queue
{
    private:
        int *cqueue_arr;
        int front, rear;
        
    public:
        circular_queue()  // constructor
        {
            cqueue_arr = new int [size];
            rear = front = -1;
        }
        
        //Inserting into Circular Queue
        
        void insert(int item)
        {
            if ((front == 0 && rear == size-1) || (front == rear+1))     //
            {
                cout<<"\nQueue overflowed..! Item Can't Be Inserted'"<<endl;
                return;
            }
            
            if (front == -1)
            {
                front = 0;
                rear = 0;
            }
            
            else
            {
                if (rear == size - 1)
                    rear = 0;
                    
                else
                    rear = rear + 1;
            }
            
            cqueue_arr[rear] = item ;
        }
        
        /*Delete from Circular Queue*/
        
        void delet()
        {
            if (front == -1)
            {
                cout<<"\nQueue underflow (EMPTY..!)";
                return;
            }
            
            cout<<"\nValue removed from queue is : "<<cqueue_arr[front];
            if (front == rear)
            {
                front = -1;
                rear = -1;
            }
            
            else
            {
                if (front == size - 1)
                    front = 0;
                else
                    front = front + 1;
            }
        }
        
        /*Show Circular Queue*/
        
        void show()
        {
            int front_pos = front, rear_pos = rear;
            if (front == -1)
            {
                cout<<endl<<"\nCircular Queue is Empty...!";
                return;
            }
            
            cout<<"\nValues in queue are :";
            
            if (front_pos <= rear_pos)
            {
                while (front_pos <= rear_pos)
                {
                    cout<<cqueue_arr[front_pos]<<"  ";
                    front_pos++;
                }
            }
            
            else
            {
                while (front_pos <= size - 1)
                {
                    cout<<cqueue_arr[front_pos]<<"  ";
                    front_pos++;
                }
                front_pos = 0;
                while (front_pos <= rear_pos)
                {
                    cout<<cqueue_arr[front_pos]<<"  ";
                    front_pos++;
                }
            }
            cout<<endl;
        }
};
 
 
int main()
{	
    int ch, value;
    cout<<"\nEnter Size of Queue to Perform Operations : ";
    cin>>size;
    circular_queue cq;
    do
    {
    		cout<<"\n\n********* Main Menu *********\n";  
        	cout<<"\nChoose one option from the following list ...\n";  
       	 	cout<<"\n===============================================\n";                                                                                                                                                                                             
			cout<<"\n1. Insertion "<<endl;
        	cout<<"2. Deletion "<<endl;
        	cout<<"3. Display "<<endl;
        	cout<<"4. Exit "<<endl;
        	cout<<"5. For Clear Screen"<<endl;
			cout<<"\n\nEnter your choice: ";
        	cin>>ch;
        
        switch(ch)
        {
        case 1:
            cout<<"\nPlease enter the value for insertion in queue : ";
            cin>>value; 
            cq.insert(value);
     		break;
 		case 2:
            cq.delet();
     		break;
        case 3:
            cq.show();
     		break;
 		case 4:
     		break;
     	case 5: 
     		system("cls");
			break;
 		default:
     cout<<"\nPlease enter a valid option"<<endl;
 }
    }
    
    while(ch != 4);
    return 0;
}
