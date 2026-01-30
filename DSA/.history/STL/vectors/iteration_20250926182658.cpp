#include <iostream>
using namespace std;

int main(){
    vector <int> v;

    for(int i = 0; i<10;i++){
        v.push_back(i);
    }

    vector<int>::iterator it = v.begin(); //begin points at the start index of the vector

    //case 1 if vector us {2,10,15,20}
    it++;  //10 ko point karega it 
    cout<< *(it) << " "; //pointer * points to  to the memory location and print

    //case 2
    it+=2;
    cout<<*(it)<<" ";
}