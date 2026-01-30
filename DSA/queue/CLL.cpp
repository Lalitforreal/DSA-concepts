#include <iostream>
using namespace std;


struct Node{
    public:
    int data;
    Node* next;

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

class CircularLinkedList{
private:
    Node* head;
    Node* tail;

public:
    CircularLinkedList(){
        head = nullptr;
        tail = nullptr;
    }
    void printList(Node* head){
        Node* temp = head;
        while(temp!=nullptr){
            cout<< temp->data<<" -> ";
            temp = temp->next;
        }
    }

    Node* insertAtHead(Node* head,int x){
        Node* newNode = new Node(x);
        if(head == NULL){
            head = tail = newNode;
            tail->next=head;
            return head;
        }else{
            
        }
    }

    


};





int main(){
    // Node* head = new Node(1);
    // Node* second = new Node(2);
    // Node* third = new Node(3);
    // Node* fourth = new Node(4);


    // head->next = second;
    // second->next = third;
    // third->next = fourth;
    // fourth->next = head; //important to make it circular

    CircularLinkedList cll;
    cll.insertAtHead(1);
    cll.insertAtHead(2);
    cll.insertAtHead(3);
    cll.printList();

    return 0;
}
