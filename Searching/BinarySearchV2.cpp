#include<iostream>
using namespace std;
 
int main()
{
    int array[10];
    int i, j, num, temp, keynum;
    int low, mid, high; 
    cout<<"\nENTER HOW MANY ELEMENTS TO BE STORED IN THE LIST : \n";
    cin>>num;
    cout<<"\nENTER THE ELEMENTS ONE BY ONE : \n";
    for (i = 0; i < num; i++)
    {
        cin>>array[i];
    }
    cout<<"\nINPUT ARRAY ELEMENTS : \n";
    for (i = 0; i < num; i++)
    {
        cout<<"\n"<<array[i];
    }
    /*  Bubble sorting begins */
    for (i = 0; i < num; i++)
    {
        for (j = 0; j < (num - i - 1); j++)
        {
            if (array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
    cout<<"\nSORTED ARRAY IS...\n";
    for (i = 0; i < num; i++)
    {
        cout<<"\n"<<array[i];
    }
    cout<<"\nENTER THE ELEMENT U WANT TO SEARCH : \n";
    cin>>keynum;
    
    /*  Binary searching begins */
    
    low = 1;
    high = num;
    do
    {
        mid = (low + high) / 2;
        if (keynum < array[mid])
            high = mid - 1;
        else if (keynum > array[mid])
            low = mid + 1;
    } while (keynum != array[mid] && low <= high);
    if (keynum == array[mid])
    {
        cout<<"\nSEARCH SUCCESSFUL \n";
    }
    else
    {
        cout<<"\nSEARCH FAILED \n";
    }
}
