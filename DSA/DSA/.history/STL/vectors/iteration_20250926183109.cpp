#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector <int> v = {2,10,15,20};
    

    vector<int>::iterator it = v.begin(); //begin points at the start index of the vector

    //case 1 if vector is {2,10,15,20}
    it++;  //10 ko point karega it 
    cout<< *(it) << " "; //pointer * points to  to the memory location and print

    //case 2
    it+=2;
    cout<<*(it)<<" ";
}