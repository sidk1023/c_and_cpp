//Arrayimplementation of stack and basic functions

#include <iostream>
#define MAXSIZE 101
using namespace std;
//declare our stack
int arr[MAXSIZE];
//set the top variable at imaginary index -1
int top = -1;
////////

//adding element x on stack
void push(int x)
{
    if (top == MAXSIZE - 1)//check for stack overflow
    {
        cout<<"ERROR: STACK OVERFLOW"<<endl;
        return;
    }
    arr[++top]=x;//increment the top variable and add element at that index
}
/////////////
//removing element from stack (we just need to reduce top)
void pop()
{
    if (top==-1){cout<<"ERROR: NO ELEMENT TO POP";return;}
    top--;
}
//return element at top of stack
int Top()
        {
            return arr[top];
        }
//check if stack is empty
int isempty()
{
    if (top==-1)return 1;
    return 0;
}

void Print()
{
    for(int i =0;i<=top;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


int main()
{
    push(3);push(4);push(6);
    Print();
    pop();
    Print();
    cout<<Top()<<" at index "<<top;
    return 0;
}
