#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    
    Node(int value) {   
        data = value;
        next = nullptr;
    }
};

void insertAtEnd(Node* &head, int value) {
    Node* newNode = new Node(value);

    if (head == nullptr) {   
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = newNode;
}

void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
}

void bubbleSort(Node* head){
    Node* temp = head;

    while(temp!=NULL){
        temp = temp->next;
    }
    Node* endNode = temp;

    temp = head;
    for(Node* i = head; i !=NULL; i = i->next){
        for(Node* j = i->next; j!= NULL; j=j->next){
            if(i->data > j->data){
                int temp = i->data;
                i->data = j->data;
                j->data = temp;

            }
            Node* end = j;
        }

    }
}

void bubbleSort2(Node* head){
    bool swapped;
    Node* end = nullptr;
    do{
        Node* current = head;
        swapped = false;
        while(current->next!=end){
            if(current->data > current->next->data){
                int temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = true;
            }
            current = current->next;
        }
        end = current; //shrink hogya
    }while(swapped);
}
int main() {
    Node* head = nullptr;

    insertAtEnd(head, 55);
    insertAtEnd(head, 44);
    insertAtEnd(head, 33);
    insertAtEnd(head, 22);
    insertAtEnd(head, 11);

    bubbleSort2(head);

    printList(head);
}