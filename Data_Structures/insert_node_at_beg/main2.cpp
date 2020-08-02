#include<iostream>

struct Node
{
    int data;
    Node* next;
};


Node* head = new Node;
void Insert(int x)
{
    Node* temp = new Node;
    temp->data = x;
    temp->next = head;
    head = temp;
}

int main()
{
    cout<<"how many numbers"<<endl;
    int n,i,x;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cout<<"enter a number"<<endl;
        cin>>x;
        Insert(x);
        Print();
    }
}
