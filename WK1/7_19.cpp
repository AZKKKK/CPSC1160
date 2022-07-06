#include <iostream>

using namespace std;

bool isSorted(int list[],const int size);

int main()
{
    cout << "Enter a size of the list: " << endl;
    int size;
    cin >> size;
    cout << "Enter a list: " << endl;
    int* list = new int[size];

    for (int i = 0; i < size; i++)
        cin >> list[i];

    if(isSorted(list,size))
        cout << "The list is already sorted" << endl;
    else
        cout << "The list is not sorted" << endl;


    delete[] list;
    list = nullptr;
    return 0;
}

bool isSorted(int list[], const int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        if (list[i] > list[i + 1])
            return false;
        
    }

    return true;
}