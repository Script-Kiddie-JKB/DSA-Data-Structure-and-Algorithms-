#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int n,address,key,pair_value,pair_size,counter;
int *arr;

class FoldBoundary{
    public:
    FoldBoundary(){
        cout << "Enter the no of locations:";
        cin >> n;
        arr = new int[n];
        pair_size = to_string(n-1).length();     
        for (int i = 0; i < n; i++) 
		{
            arr[i] = INT_MIN;
        }
    }

   
    bool check_duplicate(){
        for(int i=0;i<n;i++){
            if(key == arr[i]){
                return true;
            }
        }
        return false;
    }

    int get_pair(bool rev,int *val){
        int temp,rem,pow=1;
        temp = pair_size;
        pair_value = 0;
        while(temp--){
            rem = *val % 10;
            if(rev)
                pair_value = (pair_value*10) + rem;
            else{
                pair_value = (rem*pow) + pair_value;  //12345
                pow *= 10;
            }
            *val = *val/10;
        }
        return pair_value;
    }

    void hash_function(){
        if(counter<n){
            cout << "\nEnter the key value:";
            cin >> key;
            if(check_duplicate()){
                cout << "Duplicate values not allowed!";
                return;
            }
            int no_of_pair,temp=key;
            address = 0;
            no_of_pair = ceil((float)to_string(key).length()/(float)pair_size);  //work here
            for (int i=0;i<no_of_pair;i++){
                if(i==0 || i==no_of_pair-1){//Boundary pair
                    address += get_pair(true,&key);
                }else{
                    address += get_pair(false,&key);
                }
            }
            if(to_string(address).length() > pair_size){
                address = get_pair(false,&address);
            }
            if(address>=n)
                address %= n;
            if(arr[address] != INT_MIN){
                position();
            }
            arr[address] = temp;
            counter++;
        }
        else{
            cout << "\nHashtable is full!";
        }
    }
    void position()
	{
        while(arr[address] != INT_MIN)
		{
            if(address >= n){
                address = 0;
                continue;
            }
            address++;
        }
    }

    void display(){
        cout << "Address\t" << " Key" << endl;
        for (int i = 0; i < n; i++) {
            if(arr[i] != INT_MIN){
                cout << i << "\t-->\t" << arr[i] << endl;
            }
        }
    }

    void menu(){
        int choice;
        do{
            cout<<"\n*********Main Menu*********\n";  
        	cout<<"\nChoose one option from the following list ...\n";  
        	cout<<"\n===============================================\n";  
			cout << "\n1)Fold Boundary\n2)Display\n3)Exit\nEnter your choice:";
            cin >> choice;
            switch (choice) {
                case 1:
                    hash_function();
                    break;
                case 2:
                    display();
                    break;
                case 3:
                    break;
                default:
                    cout << "Please enter a valid choice!";
            }
        } while (choice!=3);
    }
};

int main() {
    FoldBoundary fb;
    fb.menu();
    return 0;
}
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int n,address,key,pair_value,pair_size,counter;
int *arr;

class FoldBoundary{
    public:
    FoldBoundary(){
        cout << "Enter the no of locations:";
        cin >> n;
        arr = new int[n];
        pair_size = to_string(n-1).length();     
        for (int i = 0; i < n; i++) 
		{
            arr[i] = INT_MIN;
        }
    }

   
    bool check_duplicate(){
        for(int i=0;i<n;i++){
            if(key == arr[i]){
                return true;
            }
        }
        return false;
    }

    int get_pair(bool rev,int *val){
        int temp,rem,pow=1;
        temp = pair_size;
        pair_value = 0;
        while(temp--){
            rem = *val % 10;
            if(rev)
                pair_value = (pair_value*10) + rem;
            else{
                pair_value = (rem*pow) + pair_value;  //12345
                pow *= 10;
            }
            *val = *val/10;
        }
        return pair_value;
    }

    void hash_function(){
        if(counter<n){
            cout << "\nEnter the key value:";
            cin >> key;
            if(check_duplicate()){
                cout << "Duplicate values not allowed!";
                return;
            }
            int no_of_pair,temp=key;
            address = 0;
            no_of_pair = ceil((float)to_string(key).length()/(float)pair_size);  //work here
            for (int i=0;i<no_of_pair;i++){
                if(i==0 || i==no_of_pair-1){//Boundary pair
                    address += get_pair(true,&key);
                }else{
                    address += get_pair(false,&key);
                }
            }
            if(to_string(address).length() > pair_size){
                address = get_pair(false,&address);
            }
            if(address>=n)
                address %= n;
            if(arr[address] != INT_MIN){
                position();
            }
            arr[address] = temp;
            counter++;
        }
        else{
            cout << "\nHashtable is full!";
        }
    }
    void position()
	{
        while(arr[address] != INT_MIN)
		{
            if(address >= n){
                address = 0;
                continue;
            }
            address++;
        }
    }

    void display(){
        cout << "Address\t" << " Key" << endl;
        for (int i = 0; i < n; i++) {
            if(arr[i] != INT_MIN){
                cout << i << "\t-->\t" << arr[i] << endl;
            }
        }
    }

    void menu(){
        int choice;
        do{
            cout<<"\n*********Main Menu*********\n";  
        	cout<<"\nChoose one option from the following list ...\n";  
        	cout<<"\n===============================================\n";  
			cout << "\n1)Fold Boundary\n2)Display\n3)Exit\nEnter your choice:";
            cin >> choice;
            switch (choice) {
                case 1:
                    hash_function();
                    break;
                case 2:
                    display();
                    break;
                case 3:
                    break;
                default:
                    cout << "Please enter a valid choice!";
            }
        } while (choice!=3);
    }
};

int main() {
    FoldBoundary fb;
    fb.menu();
    return 0;
}
