#include<iostream>
using namespace std;
int main()
{
int *a,no,n,i;

//ask user to input the number of elements to store in the array
cout<<"\nENTER HOW MANY ELEMENTS TO BE STORED IN THE LIST : ";
cin>>n; //read the number
a = new int[n]; //dynamically allocate memory for array

for(i=0;i<n;i++)	//loop to input the elements into the array
 {
 	cout<<"\nENTER A NUMBER :";
 	cin>>a[i];
 }
 	cout<<"\n\nENTER THE NUMBER TO SEARCH";
	cin>>no; 					//ask user to input the number to search

for(i=0;i<n;i++)		//loop to search the number in the list
{
 if(a[i]==no)
 {
 cout<<"\nTHE NUMBER "<<a[i]<<" FOUND IN THE LIST..!!";
 break;
 }
 else
 if(i==n-1)
 cout<<"\nTHE NUMBER IS **NOT** FOUND IN THE LIST";
 }
}
