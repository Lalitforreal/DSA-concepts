#include <iostream>
#include <vector>
using namespace std;
int main(){
    // queue <int> q;
    // q.push(1); // {1}
    // q.push(2); // {1, 2}
    // q.push(4); // {1, 2, 4}
    // q.emplace(5); //{1, 2, 4, 5}

    // q.back() += 5; //back = 5 and 5+5 = 10.
    // cout<< q.back()<< " -> ";

    // //queue rn -> {1, 2, 4, 10}
    // cout<< q.front()<< " -> "; //prints 1

    // q.pop(); //{2, 4, 10}

    // cout<<q.front()<<" -> ";
    // //swap, size, empty saem as stack
    // return 0;


    //PRIORITY QUEUE
    priority_queue <int> pq;
    pq.push(5); // {5}
    pq.push(2); //{5, 2}
    pq.push(8); //{8, 5, 2}
    pq.emplace(10); // {10, 8, 5, 2}

    cout<< pq.top()<<" "; //prints 10 

    pq.pop(); //{8, 5, 2}
    cout<<pq.top();
    return 0;
}

