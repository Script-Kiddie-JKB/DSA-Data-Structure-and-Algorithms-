#include<iostream>
#include<string>
#define MAX 20
using namespace std;

char stk[20];
int top=-1;
// Push function here, inserts value in stack and increments stack top by 1
void push(char oper)
{
    if(top==MAX-1)
    {
        cout<<"stack is full!!!!";
    }
   
    else
    {
        top++;
        stk[top]=oper;
    }
}
// Function to remove an item from stack.  It decreases top by 1
char pop()
{
    char ch;
    if(top==-1)
    {
        cout<<"stack is empty!!!!";
    }
    else
    {
        ch=stk[top];
        stk[top]='\0';
        top--;
        return(ch);
    }
    return 0;
}
int priority ( char operators )
{
    if(operators == '+' || operators =='-')
    {
        return(1);
    }
 
    if(operators == '*' || operators =='/')
    {
        return(2);
    }
 
    if(operators == '#')
    {
        return(3);
    }
 
    return 0;
}
string convert(string infix)
{
    int i=0;
    string postfix = "";   //nothing in postfix (null)
    while(infix[i]!='\0')  //until address becomes not = 0
    {       
        if(infix[i]>='a' && infix[i]<='z'|| infix[i]>='A'&& infix[i]<='Z')          
        {
            postfix.insert(postfix.end(),infix[i]);   // insert infix i into  postfix end coz postfix was null
            i++;
        }       
        else if(infix[i]=='(' || infix[i]=='{'  || infix[i]=='[')
        {
            push(infix[i]);				//push into stack
            i++;
        }        
        else if(infix[i]==')' || infix[i]=='}'  || infix[i]==']')
        {
            if(infix[i]==')')
            {
                while(stk[top]!='(')    
                {               postfix.insert(postfix.end(),pop());     //brackets not get into the stacks the it get discards
                }
                pop();
                i++;
            }
            if(infix[i]==']')
            {
                while(stk[top]!='[')
                {
                    postfix.insert(postfix.end(),pop());
                }
                pop();
                i++;
            }
 
            if(infix[i]=='}')
            {
                while(stk[top]!='{')
                {
                    postfix.insert(postfix.end(),pop());
                }
                pop();
                i++;
            }
        }
        else            
        {
            if(top==-1)				// if becomes null put into stack
            {
                push(infix[i]);
                i++;
            }
 
            else if( priority(infix[i]) <= priority(stk[top])) {
                postfix.insert(postfix.end(),pop());							//if priority of i is less than top operator of stack then push it to postfix 
               
                while(priority(stk[top]) == priority(infix[i])){
                    postfix.insert(postfix.end(),pop());				// if equal push it to postfix
                    if(top < 0) {
                        break;			//nothing in stack break it
                    }
                }
                push(infix[i]);
                i++;
            }
            else if(priority(infix[i]) > priority(stk[top])) {
                push(infix[i]);				//push it to stack
                i++;
            }
        }
    }
    while(top!=-1)
    {
        postfix.insert(postfix.end(),pop());   // pop it until top of the stack is -1
    }
    cout<<"The converted postfix string is : "<<postfix; //print postfix conversion  
    return postfix;
}

int main()
{
    
    string infix, postfix;
    cout<<"\nEnter the infix expression : "; //enter expression
    cin>>infix;
    postfix = convert(infix);
    return 0;
}

