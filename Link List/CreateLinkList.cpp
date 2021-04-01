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
    while(choice != 11)   
    {  
        cout<<"\n\n********* Main Menu *********\n";  
        cout<<"\nChoose one option from the following list ...\n";  
       	cout<<"\n===============================================\n";  
        cout<<"\n1.Insert in begining\n2.Insert at last\n3.Insert at any random location\n4.Delete from Beginning\n5.Delete from last\n6.Delete node after specified location\n7.Search for an element\n8.Show\n9 rever\n10.count \n11.Exit\n12.For Clear Screen";  
        cout<<"\n\nEnter your choice: ";         
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
            randominsert();       
            break;  
            case 4:  
            begin_delete();       
            break;  
            case 5:  
            last_delete();        
            break;  
            case 6:  
            random_delete();          
            break;  
            case 7:  
            search();         
            break;  
            case 8:  
            display();        
            break;
			case 9:
			reverse();
			break;
			case 10:
			count();  
            case 11:  
            exit(0);  
            break; 
			case 12:
			system("cls");
			break; 
            default:  
            cout<<"\nPlease enter valid choice..";  
        }  
    }  
}  

void beginsert()
  {
    node *temp=new node;
   	int value;
  	if(temp==NULL)
	{ 
cout <<"\nOverflow";

}
else 
{
cout<<"enter value";
cin>>value;
    temp->data=value;
    temp->next=head;
    head=temp;
cout <<" node inserted";
  }
}  
void lastinsert()  
{  
    struct node *ptr,*temp;  
    int item;     
    ptr = (struct node*)malloc(sizeof(struct node));      
    if(ptr == NULL)  
    {  
        cout<<"\nOVERFLOW";     
    }  
    else  
    {  
        cout<<("\nEnter value?\n");  
        cin>>item;  
        ptr->data = item;  
        if(head == NULL)  
        {  
            ptr -> next = NULL;  
            head = ptr;  
            cout<<"\nNode inserted";  
        }  
        else  
        {  
            temp = head;  
            while (temp -> next != NULL)  
            {  
                temp = temp -> next;  
            }  
            temp->next = ptr;  
            ptr->next = NULL;  
            cout<<"\nNode inserted";  
          
        }  
    }  
}  
void randominsert()  
{  
    int i,loc,item;   
    struct node *ptr, *temp;  
    ptr = (struct node *) malloc (sizeof(struct node));  
    if(ptr == NULL)  
    {  
        cout<<"\nOVERFLOW";  
    }  
    else  
    {  
        cout<<"\nEnter element value";  
        cin>>item;  
        ptr->data = item;  
        cout<<"\nEnter the location (Eg: 0,1,2,3,4 Index of The data) after which you want to insert ";  
        cin>>loc;  
        temp=head;  
        for(i=0;i<loc;i++)  
        {  
            temp = temp->next;  
            if(temp == NULL)  
            {  
                cout<<"\ncan't insert\n";  
                return;  
            }  
          
        }  
        ptr ->next = temp ->next;   
        temp ->next = ptr;   
        cout<<"\nNode inserted";  
    }  
}  
void begin_delete()  
{  
    struct node *ptr;  
    if(head == NULL)  
    {  
        cout<<"\nList is empty\n";  
    }  
    else   
    {  
        ptr = head;  
        head = ptr->next;  
        free(ptr);  
        cout<<"\nNode deleted from the begining ...\n";  
    }  
}  
void last_delete()  
{  
    struct node *ptr,*ptr1;  
    if(head == NULL)  
    {  
        cout<<"\nlist is empty";  
    }  
    else if(head -> next == NULL)  
    {  
        head = NULL;  
        free(head);  
        cout<<"\nOnly node of the list deleted ...\n";  
    }  
          
    else  
    {  
        ptr = head;   
        while(ptr->next != NULL)  
        {  
            ptr1 = ptr;  
            ptr = ptr ->next;  
        }  
        ptr1->next = NULL;  
        free(ptr);  
        cout<<"\nDeleted Node from the last ...\n";  
    }     
}  
void random_delete()  
{  
    struct node *ptr, *temp;  
    int val;  
    cout<<"\n Enter the data after which the node is to be deleted : ";  
    cin>>val;  
    ptr = head;  
    while(ptr -> data != val)  
    ptr = ptr -> next;  
    if(ptr -> next == NULL)  
    {  
        cout<<"\nCan't delete\n";  
    }  
    else if(ptr -> next -> next == NULL)  
    {  
        ptr ->next = NULL;  
    }  
    else  
    {   
        temp = ptr -> next;  
        ptr -> next = temp -> next;  
          
        free(temp);  
        cout<<"\nnode deleted\n";  
    }     
}  
void search()  
{  
    struct node *ptr;  
    int item,i=0,flag;  
    ptr = head;   
    if(ptr == NULL)  
    {  
        cout<<"\nEmpty List\n";  
    }  
    else  
    {   
        cout<<"\nEnter item which you want to search ?\n";   
        cin>>item;  
        while (ptr!=NULL)  
        {  
            if(ptr->data == item)  
            {  
                cout<<"\nItem found at location"<<i+1;  
                flag=0;  
            }   
            else  
            {  
                flag=1;  
            }  
            i++;  
            ptr = ptr -> next;  
        }  
        if(flag==1)  
        {  
            cout<<"\nItem not found";  
        }  
    }     
          
}  
  
void display()  
{  
    struct node *temp;  
    temp = head;   
    if(temp == NULL)  
    {  
        cout<<"\nNothing to print";  
    }  
    else  
    {  
        cout<<"\nprinting values . . . . .\n";   
        while (temp!=NULL)  
        {  
            cout<<"\t"<<temp->data;  
            temp = temp -> next;  
        }  
    }  
}  
void reverse()
 {
    struct node *temp = NULL;
    struct node *prev = NULL;
    struct node *current = head;
    while(current != NULL) {
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
