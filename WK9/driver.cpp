#include "Store.h"
#include <iostream>
using namespace std;

int main(void){
    Store* s1 = new Store(1);
    cout << "s1: \n" << *s1;

    Store s2(*s1);
    cout << "s2: \n" << s2;

    Store s3;
    s3 = s2;
    cout << "s3: \n" << s3;

    cout << "+int:" << endl; 
    s2 = s2 + 4;
    cout << "s2: \n" << s2;

    cout << "+s:" << endl;
    s3 = s3 + s2;
    cout << "s3: \n" << s3;

    cout << "-s:" << endl; 
    s3 = s3 - *s1;
    cout << "s3: \n" << s3;

    cout << "-int:" << endl; 
    s3 = s3 - 1;
    cout << "s3: \n" << s3;

    return 0;
} 