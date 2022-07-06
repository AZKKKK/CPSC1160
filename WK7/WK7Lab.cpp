#include <iostream>
#include "DynamicArray.h"

using namespace std;

int main(){
    DynamicArray d1 = DynamicArray(12);
    int* Ad1 = d1.GetArray();
    DynamicArray* d2 = new DynamicArray(10,3,10);

    (*d2).Show();
    cout << (*d2).size << "\n\n";

    (*d2).Add(100,3);
    (*d2).Show();
    cout << (*d2).size << "\n\n";

    (*d2).AddFirst(100);
    (*d2).Show();
    cout << (*d2).size << "\n\n";

    (*d2).AddLast(100);
    (*d2).Show();
    cout << (*d2).size << "\n\n";

    (*d2).Add(4,Ad1,12);
    (*d2).Show();
    cout << (*d2).size << "\n\n";

    (*d2).Remove(1);
    (*d2).Show();
    cout << (*d2).size << "\n\n";
    
    (*d2).RemoveFirst();
    (*d2).Show();
    cout << (*d2).size << "\n\n";

    (*d2).RemoveLast();
    (*d2).Show();
    cout << (*d2).size << "\n\n";

    (*d2).Remove(19,21);
    (*d2).Show();
    cout << (*d2).size << "\n\n";

    (*d2).Sort(0,17);
    (*d2).Show();
    cout << (*d2).size << "\n\n";


    if(d2){
        delete d2;
        d2 = nullptr;
    }

    return 0;
}