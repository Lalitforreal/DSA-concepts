#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* front = NULL;
Node* rear = NULL;

// Enqueue operation
void enqueue(int x) {
    Node* temp = new Node;
    temp->data = x;

    if (front == NULL) {
        front = rear = temp;
        rear->next = front;   // circular link
    } else {
        rear->next = temp;
        rear = temp;
        rear->next = front;   // maintain circular link
    }
}

// Dequeue operation
void dequeue() {
    if (front == NULL) {
        cout << "Queue is empty\n";
        return;
    }

    if (front == rear) {
        cout << "Deleted: " << front->data << endl;
        delete front;
        front = rear = NULL;
    } else {
        Node* temp = front;
        cout << "Deleted: " << temp->data << endl;
        front = front->next;
        rear->next = front;
        delete temp;
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

// Main function
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