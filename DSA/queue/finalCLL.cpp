#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};


Node* insertAtHead(Node* head, int value){
    Node* newNode = new Node;
    newNode->data = value;
    if(head == NULL){
        newNode->next = newNode;//not null so its circular
        head = newNode;
        return head;
    }
    Node* temp = head;
    //find tail 
    while(temp->next!=head){
        temp = temp->next;
    }
    newNode->next = head;
    temp->next = head;
    head = newNode;
};


Node* insertAtEnd(Node* head, int value){
    Node* newNode = new Node;
    newNode->data = value;
    if(head == NULL){
        newNode->next = newNode;//not null so its circular
        head = newNode;
        return head;
    }

    Node* rear = head;
    while(rear->next!=head){
        rear = rear->next;
    }
    rear->next=newNode;
    newNode->next = head;
    rear = newNode;
    return head;
}


Node* insertAtPosition(Node* head, int value, int pos){
    if(pos == 1){
        insertAtHead(head,value);
    }

    Node* newNode = new Node;
    newNode->data = value;
    Node* temp = head;

    for(int i = 1; i<pos;i++){
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}
void display(Node* head){
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }

    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

int main() {
        Node* head = NULL;
        int choice, value, pos;
    
        while (true) {
            cout << "\n1.Insert at Head";
            cout << "\n2.Insert at End";
            cout << "\n3.Insert at Position";
            cout << "\n4.Display";
            cout << "\n5.Exit";
            cout << "\nEnter choice: ";
            cin >> choice;
    
            switch (choice) {
    
                case 1:
                    cout << "Enter value: ";
                    cin >> value;
                    head = insertAtHead(head, value);
                    break;
    
                case 2:
                    cout << "Enter value: ";
                    cin >> value;
                    head = insertAtEnd(head, value);
                    break;
    
                case 3:
                    cout << "Enter value and position: ";
                    cin >> value >> pos;
                    head = insertAtPosition(head, value, pos);
                    break;
    
                case 4:
                    display(head);
                    break;
    
                case 5:
                    return 0;
    
                default:
                    cout << "Invalid choice";
            }
        }
}














