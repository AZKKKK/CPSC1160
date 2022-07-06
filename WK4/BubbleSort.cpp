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

void bubble(int* arr,int begin, int end){
    if(begin == end) return;

    if(arr[begin] > arr[begin + 1]){
        int temp = arr[begin];
        arr[begin] = arr[begin + 1];
        arr[begin + 1] = temp; 
    }

    bubble(arr, begin+1, end);
}

void bubbleSort(int* arr, int begin, int end, int count) {
    
    if(count == 0) return;

    bubble(arr, begin, end);

    bubbleSort(arr, begin, end, count-1);

}




int main(){
    srand(time(NULL));
    int size = 100;
    int* arr = nullptr;
    newArray(arr, size);
    printArray(arr, size,size);

    auto start = steady_clock::now();
    bubbleSort(arr,0,size-1,size);
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