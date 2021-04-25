#include<iostream>  
#include<stdlib.h>
using namespace std;  
struct node   
{  
    int data;  
    struct node *next;   
};  
struct node *head;  
  
void beginsert ();   
void lastinsert ();  
void randominsert();  
void begin_delete();  
void last_delete();  
void random_delete();  
void display();  
void search();  
void reverse();
void count();
int main ()  
{  
    int choice =0;  
    while(choice != 9)   
    {  
        cout<<"\n*********Main Menu*********\n";  
        cout<<"\nChoose one option from the following list ...\n";  
        cout<<"\n===============================================\n";  
        cout<<"\n1.Insert in begining\n2.Insert at last\n3.Delete from Beginning\n4.Delete from last\n5.Search for an element\n6.Show\n7.Reverse\n8.Count\n9.Exit\n10.ClearScreen";  
        cout<<"\nEnter your choice?\n";         
        cin>>choice;  
        switch(choice)  
        {  
            case 1:  
            beginsert();      
            break;  
            case 2:  
            lastinsert();         
            break;  
            case 3:  
            begin_delete();       
            break;  
            case 4:  
            last_delete();        
            break;  
            case 5:  
            search();         
            break;  
            case 6:  
            display();        
            break;  
            case 7:
			reverse();
			break;
			case 8:  
            count();  
            break;
			case 9: 
            exit(0);
			case 10:
			system("cls");
			break; 
            default:  
            cout<<"\nPlease enter valid choice..";  
        }  
    }  
}  
void beginsert()  
{  
    struct node *ptr,*temp;   
    int item;   
    ptr = (struct node *)malloc(sizeof(struct node));  
    if(ptr == NULL)  
    {  
        cout<<("\nOVERFLOW");  
    }  
    else   
    {  
        cout<<"\nEnter the node data ?";  
        cin>>item;  
        ptr -> data = item;  
        if(head == NULL)  
        {  
            head = ptr;  
            ptr -> next = head;  
        }  
        else   
        {     
            temp = head;  
            while(temp->next != head)  
                temp = temp->next;  
            ptr->next = head;   
            temp -> next = ptr;   
            head = ptr;  
        }   
        cout<<"\nnode inserted\n";  
    }  
              
}  
void lastinsert()  
{  
    struct node *ptr,*temp;   
    int item;  
    ptr = (struct node *)malloc(sizeof(struct node));  
    if(ptr == NULL)  
    {  
        cout<<"\nOVERFLOW\n";  
    }  
    else  
    {  
        cout<<"\nEnter Data?";  
        cin>>item;  
        ptr->data = item;  
        if(head == NULL)  
        {  
            head = ptr;  
            ptr -> next = head;    
        }  
        else  
        {  
            temp = head;  
            while(temp -> next != head)  
            {  
                temp = temp -> next;  
            }  
            temp -> next = ptr;   
            ptr -> next = head;  
        }  
          
        cout<<"\nnode inserted\n";  
    }  
  
}  
  
void begin_delete()  
{  
    struct node *ptr;   
    if(head == NULL)  
    {  
        cout<<"\nUNDERFLOW";    
    }  
    else if(head->next == head)  
    {  
        head = NULL;  
        free(head);  
        cout<<"\nnode deleted\n";  
    }  
      
    else  
    {   ptr = head;   
        while(ptr -> next != head)  
            ptr = ptr -> next;   
        ptr->next = head->next;  
        free(head);  
        head = ptr->next;  
        cout<<"\nnode deleted\n";  
  
    }  
}  
void last_delete()  
{  
    struct node *ptr, *preptr;  
    if(head==NULL)  
    {  
        cout<<"\nUNDERFLOW";  
    }  
    else if (head ->next == head)  
    {  
        head = NULL;  
        free(head);  
        cout<<"\nnode deleted\n";  
  
    }  
    else   
    {  
        ptr = head;  
        while(ptr ->next != head)  
        {  
            preptr=ptr;  
            ptr = ptr->next;  
        }  
        preptr->next = ptr -> next;  
        free(ptr);  
        cout<<"\nnode deleted\n";  
  
    }  
}  
  
void search()  
{  
    struct node *ptr;  
    int item,i=0,flag=1;  
    ptr = head;   
    if(ptr == NULL)  
    {  
        cout<<"\nEmpty List\n";  
    }  
    else  
    {   
        cout<<"\nEnter item which you want to search ?\n";   
        cin>>item;  
        if(head ->data == item)  
        {  
        cout<<"\nitem found at location "<<i+1;  
        flag=0;  
        }  
        else   
        {  
        while (ptr->next != head)  
        {  
            if(ptr->data == item)  
            {  
                cout<<"item found at location "<<i+1;  
                flag=0;  
                break;  
            }   
            else  
            {  
                flag=1;  
            }  
            i++;  
            ptr = ptr -> next;  
        }  
        }  
        if(flag != 0)  
        {  
            cout<<"Item not found\n";  
        }  
    }     
          
}  

void display()  
{  
    struct node *ptr;  
    ptr=head;  
    if(head == NULL)  
    {  
        cout<<"\nnothing to print";  
    }     
    else  
    {  
        cout<<"\n printing values ... \n";  
          
        while(ptr -> next != head)  
        {  
          
            cout<<"\t"<< ptr -> data;  
            ptr = ptr -> next;  
        }  
        cout<<"\t" << ptr -> data;  
    }  
}

void reverse()
 {
    struct node *temp = NULL;
    struct node *prev = NULL;
    struct node *current = head;
    while(current != NULL) 
	{
        temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
    }
    head = prev;
}

void count()
{
  
    struct node* temp = head;
 
    int count=0;
 
    while(temp != NULL){
 
       temp = temp->next;
        count++;
 
    }
 
 
    cout<<"\n Total no. of nodes is : "<<count;
 
}
 
