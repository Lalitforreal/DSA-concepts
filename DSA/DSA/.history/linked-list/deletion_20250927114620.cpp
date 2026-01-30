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
    if (head == NULL){
        return head;
    }
    Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

void deleteTail(Node* head){
    if(head == NULL || head->next == NULL){ //edge cases
        NULL;
    }
    Node* temp = head;
    while(temp->next->next != nullptr){
        temp=temp->next;
    }
    free(temp->next);
    temp->next = nullptr;
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


    // cout<< "head deleted list: ";
    // printList(deleteHead(head));

    cout<< "tail deleted list: ";
    deleteTail(head);
    printList(head);
    return 0;

}
