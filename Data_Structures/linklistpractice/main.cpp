//this is a reference for some common functions with linked list implementation in c++. if you are using c,
//please note that in every place we declare a node, we must use "struct Node" in place if "Node". this should be applied in every function
//declaration also. cout function may not work depending on your compiler so use printf. 
//functions include: insert at start, after a give node, at end. reversing iterative and recursive. print recursive and iterative.

#include <iostream>
using namespace std;
struct Node//basic structure of our node. 
{
    int data;
    Node* next;//the link. if you are using c, please use "struct Node* next;" instead
};


//////////////////////////////////////////////////////////////////////////////////////////////
void push(Node** head_ref, int new_data)//a function to insertnode at start of linked list. we pass in adress of head node and value of new data
{
    Node* new_node = new Node();//create a new node. if you are using c, struct Node* new_node = (struct Node*) malloc(sizeof(struct Node)); 
    new_node->data = new_data;//the data of new node is assigned
    new_node->next = (*head_ref);//link the new node to the head node(so new node points to head node)
    (*head_ref) = new_node;//new node becomes the head node. we pass in the head node by reference
}


/////////////////////////////////////////////////////////////////////////////////////////
void insertafter(Node* prev_node, int new_data)//insert a new node after a given previous node
{
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = prev_node->next;//the new node should point to the same node the old node was pointing to
    prev_node->next = new_node;//previous node now points to the new node, thus new node is inserted after previous node

}


//////////////////////////////////////////////////////////////////////////////////////////
void append(Node** head_ref, int new_data)//append a node to the end of the list
{
    Node* new_node = new Node();
    new_node->data = new_data;
    Node *traverser = (*head_ref);//create a temporary node originally pointed at our linked list's 
                                  //head node, this node will be used to traverse the linked list to the end
    new_node->next = NULL;//terminate the linked list(as our new node is the last node in our list)
    if((*head_ref)==NULL)//if the list is empty
    {
        (*head_ref)=new_node;//this is basically the same as the push function above
        return;
    }
    while(traverser->next !=NULL)//a while loop to traverse the linked list
    {
        traverser = traverser->next;//we move to the last node
    }
    traverser->next = new_node;//we attach the last node to the new node
    return;
}


//////////////////////////////////////////////////////////////////////////////////////////////

void Delete(Node** head_ref, int n)//delete a node at a given index
{
    Node* temp = (*head_ref);//create a temporary node to traverse the linked list. it points to where head node points(i.e, to the first node)
    if (n==0)//if you want to delete the first node
    {
        (*head_ref) = temp->next;//temp->next is the second node. therefore we make head node point to the second node, in effect deleting the first
        delete temp;//free from heap the temp node. if you are using C, you must use "free(temp)" instead
        return;
    }
    for(int i=0; temp!=NULL&&i<n-1;i++)//loop to traverse the linked list to the node just before the one we want to delete
    {
        temp = temp->next;
    }
    if(temp==NULL||temp->next==NULL)//if index is out of range
    {
        cout<<"error, index out of range of liked list";
        return;
    }//note that we have traversed the list to the node right before the one we want to delete
    Node* node = new Node();//allocate a new node
    //temp is now the node before the one we want to delete; so temp->next is the node we WANT to delete;temp->next->next is the node after the one we want to delete.
    node->next = temp->next->next;//the new node we allocated now points to the node succeeding the one we want to delete(we skip over temp->next)
    delete temp->next;//we delete the nth index node as per our instruction
    temp->next = node->next;//the node preceeding the previous node points to our new node, thus the deleted node is deleted and skipped over
}
void Reverse(Node** head_ref)//reverse a linked list using iterative approach
{
    Node *current, *next, *prev;//these are three temporary nodes used for reversing
    current = (*head_ref);//we point the current to where the head is pointing
    prev = NULL;//we assign the previous to NULL, so when the first node is reversed we can assign it to NULL and terminate it
    while(current!=NULL)//we traverse the list from first node to last
    {
        next = current->next;//the "next" node points to the node after current. this is so that when we reverse the direction of the current node, 
        //the address of the next node is not lost. we save it as "next" 
       
        current->next = prev;//the current node points to the previous node(we reverse the node). in the first iteration the first node is pointed to null.
        prev= current;//for the next iteration, the previous node becomes the current node in this iteration
        current = next;//for the next iteration, the current node becomes the next node(refer to step one in this loop)
    }
    (*head_ref)=prev;//when we come out of the iteration, current is pointing to NULL, and thus prev will be pointing to our last node(this is the first node on reversal)
                     //so we must point the head node to this node.
                     //head->first_>second->third->Null. on reversal NULL<-first<- second<- third<-head

}

///////////////////////////////////////////////////////////////////////////////////////////////\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

void recurse_reverse(Node* p, Node** head_ref)//reverse using recursion. very imp interview question
    //we pass in head node and also the head node by reference.
{
    if(p->next==NULL)//exit case: if p reaches the end of the list
        {
            *head_ref = p;//the head node points to the last node(I.e, first node on reversal)
            return;
         }
    recurse_reverse(p->next, head_ref);//recursive function call
    Node* q = p->next;// create a new node sharing the same adress as the node after p;
    q->next = p;//the reversal;
    p->next = NULL;//point p to null. by the end of the recursive process, this null will reach the first node and point it to null 

}

//////////////////////////////////////////////////////////////\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

void Print(Node* node)//simple print function
{
    while (node!= NULL)
    {
        cout<<" "<<node->data;
        node = node->next;
    }

}
void Recurse_print(Node* temp)//recursive print function
{

    if (temp==NULL)//exit case
    return;
    cout<<" "<<temp->data;
    Recurse_print(temp->next);

}
void Reverse_print(Node* temp)//reverse recursive print. does not reverse the list but prints in reverse
{

    if (temp==NULL)
    return;
    Reverse_print(temp->next);
    cout<<" "<<temp->data;


}

////////////////////////////////////////////////////////////////

//driver codes
int main()
{
    Node* head = NULL;//initiate head to null;
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
