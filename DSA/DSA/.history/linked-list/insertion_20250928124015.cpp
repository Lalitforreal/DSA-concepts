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

Node* insertTail(Node* head, int val){
    if(head == NULL){
        return new Node(val, nullptr); //kuch nai toh the inserted will be the only element present in the list
    }
    Node* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    Node* newNode = new Node(5,nullptr);
    temp->next = newNode;
    return head; 
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

    // cout<< "After inserting head: ";
    // Node* headIns = insertHead(head, 5);
    // printList(headIns);
    // cout<<endl;

    cout<< "After inserting tail: ";
    Node* tailIns = insertTail(head, 5);
    printList(tailIns);
    cout<<endl;



}