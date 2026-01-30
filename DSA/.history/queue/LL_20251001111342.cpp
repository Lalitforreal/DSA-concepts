#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = nullptr;
    }
};

class QLL{
    Node* start;
    Node* end;
    int size;
    int capacity;
    int currSize;

public:
    QLL(int capacity){
        start = nullptr;
        end = nullptr;
        size = capacity;
        currSize = 0;
    }

    void push(int val){
        Node* temp = new Node(val);
        if(currSize == 0){
            start = end = temp; //sab ek jagah 
        }
        else if(currSize == size){
            cout<<"Queue is full";
            return;
        }else{
            end -> next = temp;
            end = temp;
        }

        currSize++;
    }

    void pop(){
        if(currSize == 0){
            cout<<"Queue is empty";
            end = nullptr; //reset if empty
            return;
        }
        else{
            Node* temp = start ;
            start = start ->next;
            delete temp;
            currSize--;
        }
    }

    int topPeek(){
        if(currSize == 0){
            cout<<"Empty";
            return;
        }
        return start->data;
    }
};

int main() {
    QLL q(3);
    q.push(5);
    q.push(10);
    q.push(15);

    cout << "Front: " << q.topPeek() << endl;
    q.pop();
    cout << "Front after pop: " << q.topPeek() << endl;

    return 0;
}


