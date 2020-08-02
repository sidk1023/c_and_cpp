#include <iostream>

using namespace std;
struct Node
{
    int data;
    Node* next;
};
void push(Node** head_ref, int new_data)
{
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void insertafter(Node* prev_node, int new_data)
{
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;

}
void append(Node** head_ref, int new_data)
{
    Node* new_node = new Node();
    new_node->data = new_data;
    Node *traverser = (*head_ref);
    new_node->next = NULL;
    if((*head_ref)==NULL)
    {
        (*head_ref)=new_node;
        return;
    }
    while(traverser->next !=NULL)
    {
        traverser = traverser->next;
    }
    traverser->next = new_node;
    return;
}
void Delete(Node** head_ref, int n)
{
    Node* temp = (*head_ref);
    if (n==0)
    {
        (*head_ref) = temp->next;
        delete temp;
        return;
    }
    for(int i=0; temp!=NULL&&i<n-1;i++)
    {
        temp = temp->next;
    }
    if(temp==NULL||temp->next==NULL)
    {
        cout<<"error";
        return;
    }
    Node* node = new Node();
    node->next = temp->next->next;
    delete node;
    temp->next = node->next;
}
void Reverse(Node** head_ref)
{
    Node *current, *next, *prev;
    current = (*head_ref);
    prev = NULL;
    while(current!=NULL)
    {
        next = current->next;
        current->next = prev;
        prev= current;
        current = next;
    }
    (*head_ref)=prev;

}
void Print(Node* node)
{
    while (node!= NULL)
    {
        cout<<" "<<node->data;
        node = node->next;
    }

}
int main()
{
    Node* head = NULL;
    push(&head, 3);
    push(&head,2);
    append(&head, 5);
    Reverse(&head);
    Reverse(&head);

    Print(head);
    return 0;
}
