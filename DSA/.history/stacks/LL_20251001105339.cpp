#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = nullptr;
    }
};

class StackLL{
    Node* top;

public:
    StackLL(){ //initialize
        top = nullptr;
    }

    void push(int val){
        Node* temp = new Node(val);
        temp->next = top;
        top = temp;
    }

    void pop(){
        if(top == nullptr){
            cout<<"empty stack\n";
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    int peek(){
        if(top == nullptr){
            cout<<"empty stack\n";
            return 0;
        }
        return top->data;
    }
};

int main(){
    StackLL s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout<< s.peek(); 
}

