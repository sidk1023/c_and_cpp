#include <iostream>

using namespace std;
//linked list node
struct Node
{
    int data;
    struct Node* next;
};
//insert new node infront
void push(Node** head_ref, int new_data)
{
    //allocate node
    Node* new_node = new Node();

    //put the data
    new_node->data = new_data;

    //make next of new node as head
    new_node->next = (*head_ref);

    //move the head to point to new node
    (*head_ref) = new_node;
}
//insert new node after previous node
void insertafter(Node* prev_node, int new_data)
{
    //check if previous node = null
    if(prev_node == NULL){cout<<"the given previous is null"; return;}

    //allocate new node
    Node* new_node = new Node();
    //put the data
    new_node->data = new_data;
    //make next of new node as next of prev node
    new_node->next = prev_node->next;
    //make next of prev node as new node
    prev_node->next= new_node;
}

//append at end
void append(Node**head_ref, int new_data)
{
    //allocate new node
    Node* new_node = new Node();
    Node *last = *head_ref;

    //put new data
    new_node->data = new_data;
    //terminate list
    new_node->next == NULL;

    //if linked list is empty, make the new node as head
    if(*head_ref==NULL){*head_ref = new_node;return;}
    //else traverse till the end
    while(last->next != NULL){last = last->next;}
     //change next of last node
    last->next = new_node;
    return;

}
//print
void printlist(Node *node)
{
    while (node!= NULL)
    {
        cout<<" "<<node->data;
        node = node->next;
    }
}

int main()
{
 Node*head = NULL;//empty list

append(&head, 6);
push(&head,7);
push(&head,1);
append(&head,4);
insertafter(head->next,8);//inserts after 7
printlist(head);
    return 0;

}
