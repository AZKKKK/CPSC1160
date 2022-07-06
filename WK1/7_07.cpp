#include <iostream>

using namespace std;


int main()
{
    
    const int size = 10;
    int* counts = new int[size];

    for (int i = 0; i < size; i++)
        counts[i] = 0;
    

    for (int i = 0; i < 100; i++)
    {
        int value = (int)(rand() % 10); 
        counts[value] ++;
    }

    for (int i = 0; i < size; i++)
        cout << "Count for " << i << " is " << counts[i] << endl;


    delete[] counts; 
    counts = nullptr;
    return 0;
}

