#include <iostream>

using namespace std;
struct Node{
int data;
Node* next;
};
Node* top = NULL
void Push(int x){
Node* temp = new Node();
temp->data= x;
temp->next = top;
top = temp;
}
void Pop(){
if(top==NULL)return;
Node* temp=top;
top = top->next;
free(temp)
}
int main()
{

}
