

#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* front = nullptr;
Node* rear = nullptr;

void enqueue(int x){
    Node* newNode = new Node;
    newNode->data = x;

    if(front == nullptr){
        front = rear = newNode;
        rear->next = front;
    }else{
        rear->next = newNode;
        rear = newNode;
        rear->next = front;
    }
}

void dequeue(){
    if(front == nullptr){
        cout<<"Empty queue"<<endl;
    }

    if(front == rear){
        cout<<"Deleted";
        delete front;
        front = rear = nullptr;
    }else{
        Node* temp = front;
        front = front->next;
        delete temp;
        rear->next= front;
    }
}


// Display operation
void display() {
    if (front == NULL) {
        cout << "Queue is empty\n";
        return;
    }

    Node* temp = front;
    cout << "Queue elements: ";

    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != front);

    cout << endl;
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();

    dequeue();
    display();

    enqueue(40);
    display();

    return 0;
}