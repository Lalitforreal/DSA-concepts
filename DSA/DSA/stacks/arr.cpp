#include <iostream>
using namespace std;

class Stack{
    int* arr;
    int top;
    int capacity;

public:
    Stack(int size){
        arr = new int[size];
        capacity = size;
        top = -1; //initially stack empty
    }

    void push(int x){
        if(top == capacity - 1){
            cout<< "Stack Overflow\n";
            return;
        }
        arr[++top] = x;
    }

    void pop(){
        if(top == -1){
            cout<<"Stack Underflow \n";
            return;
        }
        top-- ;
    }

    int topPeek(){
        if(top == -1){
            cout<<"Stack is empty\n";
            return 0;
        }
        return arr[top];
    }
};

int main(){
    Stack s(10);
    s.push(4);
    s.pop();
    s.push(5);
    s.push(6);
    s.push(10);
    s.pop();
    cout<<s.topPeek();
}