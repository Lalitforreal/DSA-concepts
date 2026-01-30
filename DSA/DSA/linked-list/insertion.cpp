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

void printList(Node* head){
    Node* temp = head;
    while(temp!=nullptr){
        cout<< temp->data<<" -> ";
        temp = temp->next;
    }

}

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

Node* insertK(Node* head, int val, int k){

    //no LL
    if(head == NULL){
        if(k==1){
            return new Node(val, nullptr);
        }else{
            return NULL;
        }
    }

    //when a LL exists
    if(k == 1){
        Node* temp = new Node(val, head);
        return temp;
    }

    //for middle of anywhere
    int count = 0;
    Node* temp = head;
    while(temp!=nullptr){ //last tak traverse
        count++;
        if(count == (k-1)){
            Node* newEl = new Node(val, temp->next); //elem ka next point karta hai temp->next ko point
            temp->next = newEl;
        }else{
            temp = temp->next;
        }
    }
    return head;
}


Node* insertBeforeVal(Node* head, int el, int val){ //el = value to insert adn val = before which value to insert
    //no LL
    if(head == NULL){ //LL empty toh before "what" you'll insert
        return NULL;
    }
 
    //when a LL exists
    if(head->data == val){
        Node* temp = new Node(el, head);
        return temp;
    }

    //for middle of anywhere
    Node* temp = head;
    while(temp->next!=NULL){ //last tak traverse
        if(temp->next->data == val  ){
            Node* newEl = new Node(el, temp->next); //elem ka next point karta hai temp->next ko point
            temp->next = newEl;
            break;
        }else{
            temp = temp->next;
        }
    }
    return head;
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

    // cout<< "After inserting tail: ";
    // Node* tailIns = insertTail(head, 5);
    // printList(tailIns);
    // cout<<endl;

    // cout<< "Insert at K'th posn: ";
    // Node* kIns = insertK(head,100,3);
    // printList(kIns);
    // cout<<endl;
    // return 0;
    cout<< "Insert before val: ";
    Node* valIns = insertBeforeVal(head,100,3);
    printList(valIns);
    cout<<endl;
    return 0;
}