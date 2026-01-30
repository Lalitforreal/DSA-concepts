#include <iostream>
using namespace std;

struct Node{
    public:
    int data;
    Node* next;

    public: //constructor 
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};


Node* convertArrToLL(vector <int>& arr){ //we can't return the whole LL so we return the pointer to the head
     Node* head = new Node(arr[0]);
     Node* mover = head; //head se start
     for(int i = 1; i < arr.size(); i++){ //start from arr[1] cause head= arr[0]
        Node* temp = new Node(arr[i]);
        mover->next = temp; //nullptr ki jagah ab new index ko point karega
        mover++;
     }
     return head;
}


int main(){
    // int x = 5;
    // int* y = &x;
    // cout<< *y;
    // return 0;

    vector <int> arr = {2,5,8,7};
    Node* head = convertArrToLL(arr);
    Node* temp = head;
    while(temp != nullptr){
        cout<< temp->data<<" ";
        temp = temp->next;
    }



    return 0;




    // Node* y = new Node(arr[0]);
    // cout<<y << endl; // this will give me teh address
    // //to get the data inside of this I need to 
    // cout<< y->data; //prints 2
    // return 0;
}