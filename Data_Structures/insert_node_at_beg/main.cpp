#include <iostream>

using namespace std;
struct Node
{
int data;
Node* next;
} ;
struct Node* head;
void Insert(int x){
    cout<<head->next;
 Node* temp = new Node();
 temp->data = x;
 temp->next = head;
 //temp->next = NULL;
 //if(head!= NULL) temp->nest = head;
 head = temp;
}
void Print()
{
    Node*temp =head;
    while (temp!=NULL)
    {
        cout<<' '<<temp->data;
        temp = temp->next;
    }
    cout<<endl;
}
int main()
{
  head = NULL;//empty list
  cout<<"how many numbers"<<endl;
  int n,i,x;
  cin>>n;
  for(i=0;i<n;i++){
    cout<<"enter the number"<<endl;
    cin>>x;
    Insert(x);
    Print();
  }

    return 0;
}
