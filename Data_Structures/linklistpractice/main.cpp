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
        cout<<"error, index out of range of liked list";
        return;
    }
    Node* node = new Node();
    node->next = temp->next->next;
    delete temp->next;
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
void recurse_reverse(Node* p, Node** head_ref)

{

    if(p->next==NULL)
        {
            *head_ref = p;
            return;
    }
    recurse_reverse(p->next, head_ref);
    Node* q = p->next;
    q->next = p;
    p->next = NULL;


}
void Print(Node* node)
{
    while (node!= NULL)
    {
        cout<<" "<<node->data;
        node = node->next;
    }

}
void Recurse_print(Node* temp)
{

    if (temp==NULL)
    return;
    cout<<" "<<temp->data;
    Recurse_print(temp->next);

}
void Reverse_print(Node* temp)
{

    if (temp==NULL)
    return;
    Reverse_print(temp->next);
    cout<<" "<<temp->data;


}
int main()
{
    Node* head = NULL;
    append(&head, 3);//3
    append(&head,2);//3,2
    append(&head, 5);//3,2,5

    Reverse(&head);//
    Print(head);//5,2,3
    cout<<endl;
    Reverse_print(head);//3,2,5, but list is still 5,2,3
    cout<<endl;

     recurse_reverse(head,&head);//5,2,3
     Print(head);
    return 0;
}
