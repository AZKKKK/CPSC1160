#include <iostream>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

void newArray(int* &arr, int size) {

    if(size == 0) return;
    if(arr == nullptr) arr = new int[size];
    
    arr[size - 1] = (rand() % 10) + (rand() % 100);
    newArray(arr, size-1);
}

void printArray(int* arr, int size, int sizeCopy) {
    if(size == 0) return;
    cout << arr[sizeCopy - size] << " ";
    printArray(arr, size-1, sizeCopy);
}

int findSmallest(int* arr, int begin, int end){
    if(begin == end) return begin;
    int smallestInd = findSmallest(arr, begin+1, end);

    if(arr[smallestInd] < arr[begin])
        return smallestInd;
    else
        return begin;
}

void selectionSort(int* arr, int begin, int end){
    if(begin == end) return;

    int smallestInd = findSmallest(arr, begin, end);
    int smallest = arr[smallestInd];

    if(smallest != arr[begin]){
        arr[smallestInd] = arr[begin];
        arr[begin] = smallest;
    }

    selectionSort(arr, begin+1, end);
}


int main(){
    srand(time(NULL));
    int size = 100;
    int* arr = nullptr;
    newArray(arr, size);
    printArray(arr, size,size);

    auto start = steady_clock::now();
    selectionSort(arr,0,size-1);
    auto stop = steady_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);

    cout << endl << endl ;
    printArray(arr, size,size);
    cout << endl << "Time: "  << duration.count() << endl;

    if(arr != nullptr){
        delete [] arr;
        arr = nullptr;
    }
    return 0;
}