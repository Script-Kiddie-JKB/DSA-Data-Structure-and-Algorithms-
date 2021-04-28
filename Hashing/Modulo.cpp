#include<iostream>
using namespace std;

class modulo
{
	private:
		int choice,N,a[1000];
	
	public:
		void initialise(){
			cout<<"Enter size of Array"<<endl;
			cin>>N;
			for(int i=0;i<N;i++)
			{  //to avoid printing junk values
				a[i]=0;
			}
		}
		void menu()
		{
			while(choice!=3)
			{
				cout<<"\n*********Main Menu*********\n";  
        		cout<<"\nChoose one option from the following list ...\n";  
        		cout<<"\n===============================================\n";  
				cout << "\n1)Insert Key Value\n2)Display\n3)Exit\nEnter your choice:";
				cin>>choice;
				
				switch(choice)
				{
					case 1: input_key();
						break;
					case 2: display();
						break;
					case 3: 
						break;
					default: cout<<"Please enter a valid number"<<endl;
				}	
			}
		}
		void input_key()
		{
			int key,L;
			cout<<"\nEnter Key value"<<endl;
			cin>>key;
			L=key%N;
			while(a[L]!=0)
			{
				if(L==N-1)
				{
					L=0;
				}
				else
				{
					L++;
				}
			}
			a[L]=key;
		}
		void display()
		{
			int i;
			cout<<"Location"<<"     "<<"key value"<<endl;
			for(i=0;i<N;i++)
			{
				if(a[i]!=0)
				{ 
					cout<<i<<"            "<<a[i];	
					cout<<endl;
				}
			}
		}
};
int main()
{
	modulo m;
	m.initialise();
	m.menu();
	return 0;
}
