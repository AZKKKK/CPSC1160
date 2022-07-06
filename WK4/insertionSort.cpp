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

void insert(int* arr, int begin,int value){
    if(begin <= 0) return;

    if(arr[begin-1] > value){
        arr[begin] = arr[begin-1];
        arr[begin-1] = value;
    }else{
        return;
    }

    insert(arr, begin-1,value);
}

void insertionSort(int* arr,int begin ,int end){
    if(begin > end) return;

    int value = arr[begin];
    insert(arr,begin,value);
    
    insertionSort(arr,begin+1,end);

}
int main(){
    srand(time(NULL));
    int size = 100;
    int* arr = nullptr;
    newArray(arr, size);
    printArray(arr, size,size);

    auto start = steady_clock::now();
    insertionSort(arr,1,size-1);
    auto stop = steady_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);

    cout << endl << endl ;
    printArray(arr, size,size);
    cout << endl << "Time: " << duration.count() << endl;

    if(arr != nullptr){
        delete [] arr;
        arr = nullptr;
    }
    return 0;
}