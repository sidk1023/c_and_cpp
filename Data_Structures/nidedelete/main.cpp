#include <iostream>

using namespace std;
struct Node
{
    int data;
    Node* next;
};
void append(Node** head_ref, int new_data)
{
    Node* new_node = new Node();
    new_node->data = new_data;
    Node *last = (*head_ref);
    new_node->next=NULL;
    if( (*head_ref) == NULL)
    {

        (*head_ref) = new_node;
        return;
    }
    while(last->next != NULL)
    {
        last = last->next;
    }
    last->next = new_node;
    return;
}
void Delete(Node** head_ref, int n)
{
    Node* temp = (*head_ref);
    if(n==0)
    {
        (*head_ref) =temp->next;
        delete temp;
    }
    for(int i =0;temp!=NULL&&i<n-1;i++)
    {
        temp =  temp->next;
    }
    if(temp==NULL||temp->next == NULL)
        return;
    Node* node = new Node;
    node->next = temp->next->next;
    delete temp->next;
    temp->next = node->next;


}
void Print(Node* node)
{
    while(node!=NULL )
    {
        cout<<" "<<node->data;
        node=node->next;
    }
}
int main()
{
    Node* head = NULL;

    append(&head,3);
    append(&head, 4);
    Delete(&head, 1);
    Print(head);
    return 0;
}
