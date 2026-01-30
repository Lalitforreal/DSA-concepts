#include <iostream>
using namespace std;

struct Node{
    public:
    int data;
    Node* next;

    public: //constructor 
    Node(int data1, Node* next1){
        data = data1;
        next = nullptr;
    }
};

int main(){
    // int x = 5;
    // int* y = &x;
    // cout<< *y;
    // return 0;

    vector <int> arr = {2,5,8,7};
    Node* y = new Node(arr[0], nullptr);
    cout<<y << endl; // this will give me teh address
    //to get the data inside of this I need to 
    cout<< y->data; //prints 2
    return 0;
}