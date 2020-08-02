#include <iostream>

using namespace std;
    struct Node
    {
        int data;
        Node* link;
    };
int main()
{
// Node* A;
// A= nullptr; //pointer pointing to head
// Node* temp;
// temp = (Node*)malloc(sizeof(Node));
// //(*temp).data = 2;
// (*temp).link = nullptr;
// A = temp;
//
Node* A;//pointer to head node
A = NULL;//when list is empty
Node* temp = new Node();
temp->data = 2;
temp->link = NULL;
A=temp;//we link the first block to head
}
