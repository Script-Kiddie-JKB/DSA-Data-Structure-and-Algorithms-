#include <iostream>
using namespace std;
int stack[50], n, top=-1;  //top=address of stack
void push(int val) 
{
   if(top>=n-1)
   cout<<"\nStack Overflow";
   else 
   {
      top++;  //adding value to the stack address
      stack[top]=val;
   }
}
void pop()
 {
   if(top<=-1)      //if top is <= null
   cout<<"\nStack Underflow";
   else 
   {
      cout<<"\nThe Popped/Deleted element is "<< stack[top] ;
      top--;   //deleting address of stack
   }
}
void display() {
   if(top>=0) {
      cout<<"\nStack elements are:";
      for(int i=top; i>=0; i--)  
      cout<<stack[i]<<" ";
      cout<<endl;
   } else
   cout<<"\nStack is empty";
}

int main() 

{
   int ch, val;
   cout<<"\nEnter Stack Size : ";
   cin>>n;
   cout<<"******* M E N U ********";
   cout<<"\n1) Push in stack";
   cout<<"\n2) Pop from stack";
   cout<<"\n3) Display stack[PRINT STACK]";
   cout<<"\n4) Exit";
   do
    {
      cout<<"\nEnter choice: ";
      cin>>ch;
      switch(ch)
	   {
         case 1:
		  {
            cout<<"\nEnter value to be Pushed/Add:";
            cin>>val;
            push(val);
            break;
         }
         case 2:
		  {
            pop();
            break;
         }
         case 3: 
		 {
            display();
            break;
         }
         case 4: 
		 {
            cout<<"Exit"<<endl;
            break;
         }
         default:
		  {
            cout<<"\nInvalid Choice..! Select From Above Choices";
         }
      }
   }
   while(ch!=4);
   return 0;
}
