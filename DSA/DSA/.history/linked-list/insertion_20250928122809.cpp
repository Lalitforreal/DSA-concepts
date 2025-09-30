#include <iostream>
using namespace std;

struct Node{
    public:
    int data;
    Node* next;

    public:
    Node(int data1, Node* next1){ //constructor
        data = data1;
        next = next1;
    }
};


Node* insertHead(Node* head, int val){
    Node* temp = new Node(val, head);
    return temp;
}




void printList(Node* head){
    Node* temp = head;
    while(temp!=nullptr){
        cout<< temp->data<<" -> ";
        temp = temp->next;
    }

}

int main(){
    Node* head = new Node(1,nullptr);
    head->next = new Node(2,nullptr);
    head->next->next = new Node(3,nullptr);
    head->next->next->next = new Node(4,nullptr);

    // LL -> 1->2->3->4
    cout<<"Original List: ";
    printList(head);
    cout<<endl;

}