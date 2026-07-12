// Intersection of Two Linked Lists

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
    // ~Node(){
    //     int val = this->data;
    //     if(this->next != NULL){
    //         delete next;
    //         next = NULL;
    //     }
    //     cout << "Memory is free for node with data " << val << endl;
    // }
};

void printList(Node* head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node* intersection(Node* head1, Node* head2){
    if(!head1 || !head2){
        return NULL;
    }
    
    Node* a = head1;
    Node* b = head2;

    while(a != b){
        a = (a == NULL) ? head2 : a->next;
        b = (b == NULL) ? head1 : b->next;
    }

    return a;
}

int main(){
    // Common part
    Node* common = new Node(8);
    common->next = new Node(4);
    common->next->next = new Node(5);

    //First list
    Node* node1 = new Node(4);
    node1->next = new Node(1);
    node1->next->next = common;

    cout << "First list : " << endl;
    printList(node1);

    //Second list
    Node* node2 = new Node(5);
    node2->next = new Node(6);
    node2->next->next = new Node(1);
    node2->next->next->next = common;

    cout << "Second list : " << endl;
    printList(node2);

    Node* ans = intersection(node1, node2);

    if(ans){
        cout << "Intersection starts at : " << ans->data << endl;
    }
    else{
        cout << "No intersection!" << endl;
    }

    return 0;
}