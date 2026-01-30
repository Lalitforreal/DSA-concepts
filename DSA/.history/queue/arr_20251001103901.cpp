#include <iostream>
using namespace std;

class Q{
    int *arr;
    int start;
    int end;
    int capacity;

public:
    Q(int size){
        arr = new int[size];
        capacity = size;
        currSize = 0;
        start = -1;
        end = -1;
    }


    void push(int x){
        if(currSize == size){
            cout<<"Queue is full\n";
            return;
        }if(currSize == 0){
            start = 0;
            end = 0;
        }else{
            end = (end+1)%size; //wrap around taaki shuru wale elements are used and not out of bound
        }
        arr[end] = x; //end pe insert
        currSize++;
    }

    void pop(){
        if(currSize == 0){
            cout<<"Queue is already empty\n";
            return;
        }else if(currSize == 1){
            start = -1;
            end = -1;
        }else{
            start = (start + 1)% size;
        }
        currSize -- ;
    }

    int topPeek(){
        if(currSize == 0){
            cout<<"Empty"<<endl;
            return -1;
        }
        return arr[start];
    }

};

int main() {
    Q q(5);
    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front: " << q.topPeek() << endl;
    q.pop();
    cout << "Front after pop: " << q.topPeek() << endl;

    return 0;
}