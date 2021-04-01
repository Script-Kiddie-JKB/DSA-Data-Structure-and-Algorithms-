#include<iostream>
#include<stdlib.h>
using namespace std;
 

 
void insert(int ary[],int hFn, int size){
    int element,pos,n=0;
 
	cout<<"\nEnter key element to insert :\n";
	cin>>element;
 
	pos = element%hFn;
 
	while(ary[pos]!= INT_MIN) {  // INT_MIN and INT_MAX indicates that cell is empty. So if cell is empty loop will break and goto bottom of the loop to insert element
		if(ary[pos]== INT_MAX)
            break;
		pos = (pos+1)%hFn;
		n++;
		if(n==size)
		break;      // If table is full we should break, if not check this, loop will go to infinite loop.
	}
 
	if(n==size)
        cout<<"\nHash table was full of elements\nNo Place to insert this element\n\n";
	else
        ary[pos] = element;    //Inserting element
}
 
 
void display(int ary[],int size){
	int i;
 
	cout<<"\nIndex\tValue\n";
 
	for(i=0;i<size;i++)
       cout<<"\t\n"<<i<<ary[i];
}
int main(){
	int size,hFn,i,choice;
 
	cout<<"\nEnter size of hash table : ";
	cin>>size;
 
	int ary[size];
 
	cout<<"\nEnter hash function [if mod 10 enter 10] : ";
	cin>>hFn;
 
	for(i=0;i<size;i++)
        ary[i]=INT_MIN; //Assigning INT_MIN indicates that cell is empty
 
	do{
		cout<<"\n********* Main Menu *********\n";  
        cout<<"\nChoose one option from the following list ...\n"; 
		cout<<" 1-> Insert\n 2-> Display\n 3-> Exit\n 4-> Clear Screen\n";
		cin>>choice;
 
		switch(choice){
			case 1:
				insert(ary,hFn,size);
				break;
			
			case 2:
				display(ary,size);
				break;
			
			case 3:
				exit(0);  
            	break; 	
			case 4:
				system("cls");
				break;
			default:
				cout<<"\nEnter correct choice\n";
				break;
		}
	}while(choice);
 
	return 0;
}
