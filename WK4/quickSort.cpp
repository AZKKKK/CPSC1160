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

void compareToPivot(int* arr, int pivot, int &low, int &high) {
    if(low > high) return;
    if(arr[low] <= arr[pivot]){
        low ++;
    }else if(arr[high] >= arr[pivot]){
        high --;
    }else if(low <= high){
        int temp = arr[low];
        arr[low] = arr[high];
        arr[high] = temp;
    }

    compareToPivot(arr, pivot, low, high);
}

int placePivot(int* arr, int len){
    int pivot, low, high;

    pivot = 0;
    low = 1;
    high = len - 1;

    compareToPivot(arr, pivot, low, high);

    int temp = arr[pivot];
    arr[pivot] = arr[high];
    arr[high] = temp;

    return high;

}

// Modified lecture code
void quickSort(int* arr,int len){
    if(len == 0) 
        return;
    else if(len == 1) 
        return;
    else if(len == 2){
        if(arr[0] > arr[1]){
            int temp = arr[0];
            arr[0] = arr[1];
            arr[1] = temp;
        }
        return;
    }

    int pivot = placePivot(arr, len);
    quickSort(arr, pivot);
    quickSort(arr + pivot + 1, len - pivot -1);
}

int main(){
    srand(time(NULL));
    int size = 10;
    int* arr = nullptr;
    newArray(arr, size);
    printArray(arr, size,size);

    auto start = steady_clock::now();
    quickSort(arr,size);
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