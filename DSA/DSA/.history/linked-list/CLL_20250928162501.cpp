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
    void CircularLinkedlist(){
        head = nullptr;
        tail = nullptr;
    }

    void insertAtHead(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head=tail=newNode;
            tail->next =head; //to make it circular
        }else{//when there exists a ll
            newNode->next = head;
            head = newNode;
            tail->next = head;
        }
    }

    void printList(){
        if(head==NULL){
            return;
        }

        cout<< head->data << " -> "; //atleast ek baar toh print ho head
        Node* temp = head;

        while(temp!=head){
            cout<<temp->data<<" -> ";
            temp = temp->next;
        }
        cout<< temp->data<<endl;
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

    return 0;
}