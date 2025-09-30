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

    void insertAtHead(Node* head, Node* tail, int val){
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

    void insertAtTail(Node* head, Node* tail, int val){
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

    void printList(Node* head){
        if(head==NULL){
            return;
        }
        Node* temp = head;

        do{
            cout<<temp->data<<" -> ";
            temp = temp->next;
        }while(temp!=head);

        cout<< temp->data<<endl;
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
    return 0;
}