#include <iostream>
using namespace std;

struct Node{
    public:
    int data;
    Node* next;

    public: //constructor
    Node(int data1){
        data= data1;
        next = nullptr;
    }
};


Node* deleteHead(Node* head){
    Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

void printList(Node* head){
    Node* temp = head;
    while(temp!=nullptr){
        cout<<temp->data<<" -> ";
        temp = temp -> next;
    }
}

int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    cout<<"Original list: ";
    printList(head);
    cout<<endl;

    
    cout<< "head deleted list: ";
    printList(deleteHead(head));

}
