#include <iostream>

using namespace std;
struct Node
{
    int data;
    Node* prev;
    Node* next;
};
struct Node* head;//global var, pointer to node
struct Node* GetNewNode(int x)//creates new node and returns pointer to it
{
    Node* newNode  = new Node();
    newNode->data = x;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
};
void InsertAtHead(int x)//inserts at head of a doubly linked list
{
  Node* newNode = GetNewNode(x);
  if(head==NULL)
  {
      head = newNode;
      return;
  }
  head->prev = newNode;
  newNode->next = head;
  head = newNode;
}
void InsertAtTail(int x)
{
    Node*temp = head;
    Node* newNode = GetNewNode(x);
    if(head==NULL)
    {
        head = newNode;
        return;
    }
    while(temp->next!=NULL)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}
void Print(){
Node* temp = head;
while(temp != NULL)
{
    cout<<temp->data<<" ";
    temp = temp->next;
}
}
void ReversePrint()
{
 Node* temp = head;
 if(temp==NULL)return;
 while(temp->next!=NULL){temp = temp->next;}
 while(temp!=NULL)
 {
     cout<<temp->data<<" ";
     temp = temp->prev;
 }

}

int main()
{
head = NULL;
InsertAtHead(4);
InsertAtTail(2);
InsertAtTail(3);
InsertAtTail(3);
Print();
cout<<endl;
ReversePrint();
}
