#include <iostream>
using namespace std;

int main(){
        //STACK

    stack <int> st;
    st.push(1); //{1}
    st.push(2); //{2, 1}
    st.push(3); //{3, 2, 1}
    st.push(4); //{4, 3, 2, 1}
    st.emplace(5); //{5, 4, 3, 2 ,1}


    cout<< st.top()<<endl; // prints 5

    st.pop(); //removes 5(last in first out)

    cout << st.top(); //prints 4 now

    st.size(); // ans - 4
    st.empty(); //delete everything

    stack <int> st1, st2;
    st1.swap(st2); // st1 me st2 hojaega
}