// Delete Node in a Linked List

#include<bits/stdc++.h>
using namespace std;

class Node{
public:    
    int data;
    Node* next;

    Node(int d){
        this->data = d;
        this->next = NULL;
    }
};

void printList(Node* head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void deleteNode(Node* node){
    if(node == NULL || node->next == NULL){
        cout << "Cannot delete the last node using this method.\n";
        return;
    }

    node->data = node->next->data;

    Node* temp = node->next;
    node->next = node->next->next;

    delete temp;
}

int main(){
    // Creating the linked list:
    // 10 -> 20 -> 30 -> 40

    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    cout << "Original List is : " << endl;
    printList(head);

    // Delete node containing 20
    deleteNode(head->next);

    cout << "After deleting 20 : ";
    printList(head);

    return 0;
}





// Limitation : 
// This trick cannot delete the last node because there is no next node whose data can be copied.
// That's why problems like Delete Node in a Linked List explicitly guarantee that the 
// node to delete is not the tail node.