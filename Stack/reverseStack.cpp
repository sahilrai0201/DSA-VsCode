// Reverse Stack - Recursive approach

#include<bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int> &st, int number){
    if(st.empty()){
        st.push(number);
        return;
    }

    int n = st.top();
    st.pop();

    insertAtBottom(st, number);

    st.push(n);
}

void reverseStack(stack<int> &st){
    if(st.empty()){
        return;
    }

    int num = st.top();
    st.pop();

    reverseStack(st);

    insertAtBottom(st, num);
}

int main(){
    stack<int> st;

    st.push(2);
    st.push(3);
    st.push(4);
    st.push(1);
    st.push(0);
    st.push(5);

    reverseStack(st);

    cout << "Sorted resultant stack is : " << endl;
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    return 0;
}