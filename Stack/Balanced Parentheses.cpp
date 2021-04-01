#include<iostream>
#include<string.h>
using namespace std;
char stk[30];
int top=-1;

void push(char exp)
{
 top=top+1;
 stk[top]=exp;
}
void pop()
{
 top=top-1;
}
int main()
{
 char exp[30];
 int i;
 cout<<"Enter the parenthesis expression:"<<endl;
 cin>>exp;
 for(i=0;i<strlen(exp);i++)
 {1
  if((exp[i]>='a' && exp[i]<='z') ||(exp[i]>='A' && exp[i]<='Z') ||(exp[i]>='0' && exp[i]<='9'))
         continue;
        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
     push(exp[i]);
     }
  else if(exp[i]== ')' || exp[i]== '}' || exp[i]== ']') 
  {
   pop();
  
  } 
 }
 if(top==-1)
 {
  cout<<"Given expression is Balanced:"<<endl;
 }
 else
 {
  cout<<"Given expression is not Balanced:"<<endl;
 }
}
