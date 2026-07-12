// Given the head of a singly linked list, return true if it is a palindrome or false otherwise.

// ****************************************************************************************
// APPROACH 2 : TC = O(N) & SC = O(1) : 

#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int d){
        this->data = d;
        this->next = nullptr;
    }
};

void printList(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node* reverseList(Node* head){
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

bool isPalindrome(Node* head){

    if(head == NULL || head->next == NULL){
        return true;
    }

    //find mid point
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    //reverse the list
    slow->next = reverseList(slow->next);

    Node* firstHead = head;
    Node* secondHead = slow->next;

    //compare both halves
    while(secondHead != NULL){
        if(firstHead->data != secondHead->data) return false;

        firstHead = firstHead->next;
        secondHead = secondHead->next;
    }

    return true;
}

int main(){
    Node* head = new Node(2);
    head->next = new Node(1);
    head->next->next = new Node(1);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(3);

    bool result = isPalindrome(head);

    cout << "Is given list a plaindrome? (T/F) : " << result << endl;

    return 0;
}




// *****************************************************************************************
// APPROACH 1 : TC = O(N) & SC = O(N) : 

// #include<bits/stdc++.h>
// using namespace std;

// class Node{
// public:
//     int data;
//     Node* next;
//     Node(int d){
//         this->data = d;
//         this->next = nullptr;
//     }
// };

// void printList(Node* head){
//     Node* temp = head;
//     while(temp != NULL){
//         cout << temp->data << " ";
//         temp = temp->next;
//     }
//     cout << endl;
// }

// bool checkPalindrome(vector<int> &arr){
//     int n = arr.size();

//     int s = 0;
//     int e = n-1;

//     while(s <= e){
//         if(arr[s] != arr[e]) return false;
//         s++; 
//         e--;
//     }

//     return true;
// }

// bool isPalindrome(Node* head){
//     vector<int> arr;
//     Node* temp = head;

//     while(temp != NULL){
//         arr.push_back(temp->data);
//         temp = temp->next;
//     }

//     return checkPalindrome(arr);
// }

// int main(){
//     Node* head = new Node(2);
//     head->next = new Node(1);
//     head->next->next = new Node(1);
//     head->next->next->next = new Node(2);
//     // head->next->next->next->next = new Node(3);

//     bool result = isPalindrome(head);

//     cout << "Is given list a plaindrome? (T/F) : " << result << endl;

//     return 0;
// }