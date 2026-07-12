// Sort Stack - Recursive approach

#include<bits/stdc++.h>
using namespace std;

void sortedInsert(stack<int> &st, int number){
    if(st.empty() || (!st.empty() && st.top() < number)){
        st.push(number);
        return;
    }

    int n = st.top();
    st.pop();

    sortedInsert(st, number);

    st.push(n);
}

void sortStack(stack<int> &st){
    if(st.empty()){
        return;
    }

    int num = st.top();
    st.pop();

    sortStack(st);

    sortedInsert(st, num);
}

int main(){
    stack<int> st;

    st.push(2);
    st.push(3);
    st.push(4);
    st.push(1);
    st.push(0);
    st.push(5);

    sortStack(st);

    cout << "Sorted resultant stack is : " << endl;
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    return 0;
}