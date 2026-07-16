// Pair Sum in Doubly Linked List

#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node* prev;
    
    // constructor
    Node(int d){
        this->data = d;
        this->next = NULL;
        this->prev = NULL;
    }

    // // deconstructor
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

vector<pair<int, int>> pairSum(Node* head, int target){
    vector<pair<int, int>> ans;

    if(head == NULL) return ans;

    Node* left = head;
    Node* right = head;

    while(right->next != NULL){
        right = right->next;
    }

    while(left != right && left->prev != right){
        int sum = left->data + right->data;

        if(sum == target){
            ans.push_back({left->data, right->data});
            left = left->next;
            right = right->prev;
        }
        else if(sum < target){
            left = left->next;
        }
        else{
            right = right->prev;
        }
    }

    return ans;
}

int main(){
    Node* node1 = new Node(1);

    node1->next = new Node(2);
    node1->next->prev = node1;

    node1->next->next = new Node(4);
    node1->next->next->prev = node1->next;

    node1->next->next->next = new Node(5);
    node1->next->next->next->prev = node1->next->next;

    node1->next->next->next->next = new Node(6);
    node1->next->next->next->next->prev = node1->next->next->next;

    node1->next->next->next->next->next = new Node(8);
    node1->next->next->next->next->next->prev = node1->next->next->next->next;

    node1->next->next->next->next->next->next = new Node(9);
    node1->next->next->next->next->next->next->prev = node1->next->next->next->next->next;

    int n;
    cout << "Enter the target : " << endl;
    cin >> n;

    cout << "Original List : " << endl;
    printList(node1);

    vector<pair<int, int>> result = pairSum(node1, n);

    cout << "Pairs whose sum are equal to target is : ";
    for(auto it : result){
        cout << "(" << it.first << "," << it.second << ")";
    }
    cout << endl;

    return 0;
}