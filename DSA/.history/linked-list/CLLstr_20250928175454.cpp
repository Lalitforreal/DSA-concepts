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

    void insertAtHead(Node*& head, Node*& tail, int val){
        //…it passes the pointers by value, so changing head or tail inside the
        //function does not affect the original head and tail in main.
        //Fix: Pass the pointers by reference using Node*&:
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

    void insertAtTail(Node*& head, Node*& tail, int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head= tail= newNode;
            tail->next = head;
        }else{
            newNode->next = head;
            tail->next = newNode; //only change in head and tail pehle point karvao then shift teh tail
            tail = newNode;

        }
    }

    void deleteHead(Node*& head, Node*& tail){
        if(head == NULL){
            return;
        }else{//when LL not empty
            if(head == tail){ //only a single node present
                delete head;
                head= tail = NULL;
            }else{///moe than 1 node
                Node* temp = head;
                head = head->next;
                tail->next = head;
                delete temp;    
            }
        }
    }

    void deleteTail(Node*& head, Node*& tail){
        if(head== NULL){
            return;
        }else if(head== tail){
            delete head;
            head = tail = NULL;

        }else{
            Node* temp = tail;
            Node* prev = head;
            while(prev-> next != tail){
                prev = prev->next;
            }
            tail = prev;
            tail->next = head;
            temp->next = NULL;
            delete temp;
        }
    }

    void printList(Node* head){
        if(head==NULL){
            return;
        }
        Node* temp = head;

        do{
            cout<<temp->data<<" -> ";
            temp = temp->next;
        }while(temp!=head);
        cout<<temp->data<<endl;
    }





int main(){
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);


    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = head; //important to make it circular

    Node* tail = fourth; //imp to keep track of tail 

    insertAtHead(head,tail,0);
    insertAtTail(head,tail,5);

    cout<<"After insertion: ";
    printList(head);


    cout<<"After delete head fn: ";
    deleteHead(head,tail);
    printList(head);
}