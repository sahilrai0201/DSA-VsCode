// Delete the Middle Node of a Linked List

#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    
    //constructor
    Node(int d){
        this->data = d;
        this->next = NULL;
    }

    //deconstructor
    ~Node(){
        int val = this->data;
        if(this->next != NULL){
            delete next;
            next = NULL;
        }
        cout << "Memory is free for node with data " << val << endl;
    }
};

void printList(Node* head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node* deleteMiddle(Node* head){
    Node* slow = head;
    Node* fast = head;
    Node* prev = NULL;

    while(fast != NULL && fast->next != NULL){
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    prev->next = slow->next;

    slow->next = NULL;   // Break the link
    delete slow;

    return head;
}

int main(){
    Node* node1 = new Node(10);
    node1->next = new Node(20);
    node1->next->next = new Node(30);
    node1->next->next->next = new Node(40);
    node1->next->next->next->next = new Node(50);

    cout << "List before deletion : " << endl;
    printList(node1);

    deleteMiddle(node1);

    cout << "List after deletion : " << endl;
    printList(node1);

    return 0;
}