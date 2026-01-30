#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector <int> v = {2,10,15,20};


    // vector<int>::iterator it = v.begin(); //begin points at the start index of the vector

    // //case 1 if vector is {2,10,15,20}
    // it++;  //10 ko point karega it 
    // cout<< *(it) << " "; //pointer * points to  to the memory location and print

    // //case 2 - jump 2 ahead
    // it+=2;
    // cout<<*(it)<<" ";


    // //to print the elements
    // cout<<"Vector elements: ";
    // // 1) using iterator
    // for(vector<int>::iterator it = v.begin(); it!= v.end(); it++){
        
    //     cout<<*it<<endl;
    // }

    // // 2) using auto -> just a shortcut
    // for(auto it = v.begin(); it!= v.end(); it++){
    //     cout<<*(it)<< ", ";
    // }
    // cout<<endl;

    // // 3) for-each 
    // //HERE YOU DON'T HAVE TO USE POINTER TO PRINT CAUSE it automatically iterates
    // for(auto it : v){
    //     cout<<it<< ", ";
    // }
    // cout<<endl;


    // //deletion in a vector {2, 10, 15, 20}

    // //single elements
    // v.erase(v.begin()+1); //here erase(the postion you want to delete)
    // for(auto it : v){
    //     cout<< it << ", ";
    // }
    // return 0;

    //delete a range
    v.erase(v.begin(),v.begin()+2);
    for(auto it : v){
        cout<< it << ", ";
    }
    return 0;




}