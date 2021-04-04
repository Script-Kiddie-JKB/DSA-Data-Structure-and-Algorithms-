#include <iostream>

using namespace std;
int choice,size,key,loc;
int array[1000];
int len_size,len_key;
int add;



class FoldBoundary{
 public:
 
 void menu()
 {
      cout<<" \nEnter the size of the array "<<endl;
   cin>>size;
   for(int i=0;i<size;i++)
  {
    array[i]=0;
  }
   
   do{
     cout<<"\n********* Main Menu *********\n";  
        cout<<"\nChoose one option from the following list ...\n"; 
		cout<<" 1-> Insert\n 2-> Display\n 3-> Exit\n 4-> Clear Screen\n";
       cin>>choice;
       switch(choice)
    {
     case 1:
         insert_E();
         break;
     case 2:
       display();
         break;
     case 3:
         break;
     default:
        cout<<" \nEnter proper choice "<<endl;
         break;
     } 
   }while(choice!=3);
   
    
 }
 int len( int temp_ele)
 {
  int l=0;
  while (temp_ele!=0)
  {
   l++;
   temp_ele=temp_ele/10; 
  }
  return l;
 }
 
 void insert_E(){
      
      cout<<" \nEnter the element "<<endl;
      cin>>key;
      if(key==0)
      {
       cout<<" \nCan not enter 0 as an element "<<endl;
       return;
   }
   
   sumProvider(key,size);
      
      loc=add%size;
   foldBoundHash(loc);
   cout<<" Element successfully Inserted "<<endl;    
 }
 
 
 void sumProvider(int k , int s)
 {
  len_size=len(s);
  len_key=len(k);
  int fill;
  int ext_ele=0;
  int rev_num=0;
  int t;
  int temp[10];
  int rtae=0;
  int lim;
  
  if(len_size>len_key)
  {
    fill=len_size-len_key; 
  }
  else{
    ext_ele=len_key%len_size;
    if(ext_ele!=0)
    {
     fill=len_size-ext_ele;
    }
    
  }
  t=0;
  for( int i=k;i!=0;i=i/10)
  {
   
   t=i%10;
   rev_num= (rev_num * 10)+t;
  }
  if(fill!=0)
  {
  for( int j=0;j<fill;j++)
  {
   rev_num=rev_num * 10;
  } 
  }
  int len_rev_num=len(rev_num);
  lim=len_rev_num/len_size;
  for(int l=0;l<lim;l++)
  {
   if(len_size==1)
   {
    t=0;
    t=rev_num%10;
    rev_num=rev_num/10;
   }
   else if(len_size==2)
   {
      t=0;
      t=rev_num%100;
      rev_num=rev_num/100;
   }
   else if(len_size==3)
   {
       t=0;
      t=rev_num%1000;
      rev_num=rev_num/1000;
   }
   else
   {
    return; 
   }
   temp[l]=t;
  }
        if(len_size!=1)
  {
  for(int o=0;o<lim;o++)
  {
   if(o==0 || o==(lim-1))
   {
    continue;
   }
   int laste=0;
   for(int p=temp[o];p!=0;p=p/10)
   { 
       laste=p%10;
    rtae=(rtae * 10)+laste;
   }
   temp[o]=rtae;
  }
 
 }
      
    add=0;
     for(int m=0;m<lim;m++)
   { 
     t=temp[m];
     add=add+t;
   
   }
  int len_add=len(add);
  if(len_add>len_size)
  {
   if(len_size==1)
   {
    
    add=add%10;
   }
   else if(len_size==2)
   {
      
       add=add%100;
   }
   else if(len_size==3)
   {
       
      add=add%1000;
   }
   else
   {
     
   }
  }
 
 
 }
 
 void foldBoundHash(int location)
 {
  int tloc=location;
  if(array[location]==0)
  {
   array[location]=key;
  }
  else
  {
   while(array[location]!=0)
   {
    ++location;
    if(location>=size)
    {
     location=0;
    }
    if(location==tloc)
    {
     break;
    }
   }
   if(array[location]==0)
   {
    array[location]=key;
   }
   else
   {
    if(array[location]!=0 && location==tloc)
    {
     cout<<"\nCan't Insert..! Index is full :( "<<endl;
    }
   }
  }
 }
 
 display()
 {
  bool check=false;
  for(int n=0;n<size;n++)
  {
   if(array[n]==0)
   {
    continue;
   }
   if(array[n]!=0)
   {
    check=true;
    cout<<" the element |" <<array[n]<< "| is stored in index no "<<n<<endl;
   }
  }
  if(check==false)
  {
   cout<< " no elements to display "<<endl;
  }
 }
};

int main()
{
 FoldBoundary f;
 f.menu();
 return 0;
}
