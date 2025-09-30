#include <iostream>
#include <vector>
using namespace std;
int main(){
    queue <int> q;
    q.push(1); // {1}
    q.push(2); // {1, 2}
    q.push(4); // {1, 2, 4}
    q.emplace(5); //{1, 2, 4, 5}

    q.back() += 5; //back = 5 and 5+5 = 10.
    cout<< q.back();
    return 0;
}