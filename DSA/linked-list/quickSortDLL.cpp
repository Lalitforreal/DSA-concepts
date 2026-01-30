#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int val) {
        data = val;
        prev = next = NULL;
    }
};

Node* getHigh(Node* head){
    while(head && head->next){
        head = head->next;
    }
    return head;
}

Node* partition(Node* low, Node* high){
    int pivot = high->data;
    Node* i = low->prev;

    for(Node* j = low; j!=high;j = j->next){
        if(j->data<= pivot){
            //If i is NULL → set i = low (first valid node) Else → move normally i = i->next
            i = (i == NULL) ? low : i->next;
            // i = i->next; done above
            swap(i->data,j->data);
        }
    }
    i = (i == NULL) ? low : i->next;
    swap(i->data,high->data);//i and arr[high] in array swap
    return i;//pivot return hoga
}

void quickSortRec(Node* low, Node* high){
    // Only quicksort if the sublist contains 2 or more nodes and the pointers haven’t crossed.
    if(low!=NULL && low != high && low!=high->next){
        Node* pivot = partition(low,high);
        quickSortRec(low,pivot->prev);
        quickSortRec(pivot->next,high);
    }

}

void quickSort(Node* head){
    Node* high = getHigh(head);
    quickSortRec(head,high);
}



// Insert at end
void insertEnd(Node* &head, int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

// Print list
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << "\n";
}


int main() {
    Node* head = NULL;

    insertEnd(head, 10);
    insertEnd(head, 7);
    insertEnd(head, 8);
    insertEnd(head, 9);
    insertEnd(head, 1);
    insertEnd(head, 5);

    cout << "Original DLL: ";
    printList(head);

    quickSort(head);

    cout << "Sorted DLL:   ";
    printList(head);

    return 0;
}