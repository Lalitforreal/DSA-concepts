#include <iostream>
using namespace std;


int main(){
    priority_queue<pair<int, string>, vector<pair<int, string>>,cmp > pq;
}


//{1, "apple"}
//{2 , "banana"}

struct cmp{

        // cmp(a,b) == true means a has lower priority than b
        //if cmp(a,b) == FALSE a has higher priority and at top
        
        //this func anssers tha  is a wrose than b (that worse is subjective, if you want to make a min heap, if a.first > b.first it will return false -> a is smaller)
        bool comp(pair<int,string>& a, pair<int, string>& b){
            if(a.first!= b.first){
                //if i want to make a min heap
                return a.first > b.first; //if true -> for mineheap it will reutrn true and giev priority to b so b goes on top 
                                    //if false -> for minheap a ki priority > b.priority

                //if i want to maeka max heap 
                return a.first < b.first;
            }
            //now if first is equal you compare second
        return a.second > b.second ; //if true -> b first else a first
}};

//how to figure out if its min or max?
//lets take a case where a.first = 10, b.first = 5;
// if you return a.first > b.first ; it will return true? hence cmp(a,b) == true which means a has lower priority.
//and b should come above a (smaller first wins) hence creates a MIN HEAP
// same for max heap

// cmo