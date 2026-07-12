// Given the head of a singly linked list, reverse the list, and return the reversed list.

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

Node* reverse(Node* head){
    if(head == NULL){
        return NULL;
    }
    
    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;

    while(curr != NULL){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }

    return prev;
}

int main(){
    Node* node1 = new Node(10);
    node1->next = new Node(20);
    node1->next->next = new Node(30);
    node1->next->next->next = new Node(40);
    node1->next->next->next->next = new Node(50);

    cout << "Original list : " << endl;
    printList(node1);

    node1 = reverse(node1);

    cout << "Reversed list : " << endl;
    printList(node1);

    return 0;
}