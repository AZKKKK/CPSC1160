#include <iostream>
#include <cmath>
 
using namespace std;

int max(int* arr,int begin,int end);
void fillArray(int* arr, int size, int copy);


int main()
{

    // ask for array size and content
    cout << "Enter array size: ";
    int size;
    cin >> size;
    int* arr = new int[size];
    cout << "Enter the array " << endl;
    fillArray(arr,size, size);


    // output the biggest number in the array
    cout << "The maximum number of elements in the array is " << max(arr, 0,size - 1) << endl;

    //deallocation
    delete [] arr;
    arr = nullptr;

    return 0;

}

void fillArray(int* arr, int size, int copy)
{
    if(size == 0) return;

    cin >> arr[copy - size];

    return fillArray(arr,size-1, copy);
}


int max(int* arr, int begin, int end)
{
    if(begin == end) return arr[end];


    int mid  = begin + (end - begin)/2;
    int firHalf = max(arr, begin, mid);
    int secHalf = max(arr,mid+1,end);

    if(firHalf > secHalf)
        return firHalf;
    else
        return secHalf;
}
