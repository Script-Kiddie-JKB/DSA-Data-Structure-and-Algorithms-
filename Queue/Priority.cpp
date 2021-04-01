#include <iostream>
#include <stdlib.h>

using namespace std;
 
//Declaring the node

struct node
{
	int priority;
	int data;
	struct node *link;
};

class priority_queue
{
    private:
        node *front;
    public:
        priority_queue()    
        {
            front = NULL;
            
        }
        

        void insertion(int item, int priority)
        {
            node *tmp, *q;
            tmp = new node;
            tmp->data = item;
            tmp->priority = priority;
            if (front == NULL || priority < front->priority)
            {
                tmp->link = front;
                front = tmp;
            }
            
            else
            {
                q = front;
                while (q->link != NULL && q->link->priority <= priority)
                    q=q->link;
                tmp->link = q->link;
                q->link = tmp;
            }
        }
        

        void deletion()
        {
            node *tmp;
            if(front == NULL)
                cout<<"\nQueue Underflowed "<<endl;
                
            else
            {
                tmp = front;
                cout<<"\nDeleted value is: "<<tmp->data<<endl;
                cout<<"Priority :"<<tmp->priority<<endl;
                front = front->link;
                free(tmp);
            }
        }

        void show()
        {
            node *ptr;
            ptr = front;
            if (front == NULL)
                cout<<"\nEmpty Queue "<<endl;
                
            else
            {	cout<<"\nQueue is: "<<endl;
                cout<<"\n\nPriority       Value/Queue "<<endl;
                while(ptr != NULL)
                {
                    cout<<ptr->priority<<"                 "<<ptr->data<<endl;
                    ptr = ptr->link;
                }
            }
        }
};

int main()
	
{
    int ch, val, priority;
    priority_queue pq; 
    do
    {
    	cout<<"\n\n******* MAIN-MENU *******";
        cout<<"\n\n1. Insertion "<<endl;
        cout<<"2. Deletion "<<endl;
        cout<<"3. Display "<<endl;
        cout<<"4. Exit "<<endl;
        cout<<"5. For Clear Screen"<<endl;
        cout<<"\nPlease enter your choice : "; 
        cin>>ch;
        
        switch(ch)
        {
        case 1:
            cout<<"\nPlease enter the value to be added in the queue : ";
            cin>>val;
            cout<<"\nPlease enter its priority : ";
            cin>>priority;
            pq.insertion(val, priority);
            break;
        case 2:
            pq.deletion();
            break;
        case 3:
            pq.show();
            break;
        case 4:
            break;
        case 5:
			system("cls");
			break;    
        default :
            cout<<"\nInvalid entry"<<endl;
        }
    }
    while(ch != 4);
    return 0;
}
