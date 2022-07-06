#include <iostream>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;
int count = 0;
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


void mergeBoth(int* merged, int* left, int* right, int &i, int &j, int &k, int lsize, int rsize) {
    if(i >= lsize || j >= rsize) return;

    if(left[i] <= right[j])
        merged[k++] = left[i++];
    else
        merged[k++] = right[j++];
        
    mergeBoth(merged,left,right,i,j,k,lsize,rsize);
}

void merge(int* merged, int* partArr, int pSize, int &ind, int &pInd){
    if(pInd >= pSize) return;
    merged[ind++] = partArr[pInd++];

    merge(merged, partArr,pSize,ind,pInd);

}


int* MergeInOrder(int* left, int lsize, int* right, int rsize) {
    int i, j, k;
    int* merged = new int[lsize + rsize];
    i = j = k = 0;
    mergeBoth(merged,left,right,i,j,k,lsize,rsize);
    merge(merged,left,lsize,k,i);
    merge(merged,right,rsize,k,j);


    return merged;
    
}

// Modified lecture code
int* mergeSort(int* arr, int size){
    // NOT an inplace sort, returns a new array with sorted values
    count ++;
    if(size == 0){
        int* newArray = nullptr;
        return newArray;
    }
    else if(size == 1){
        int* newArray = new int[size];
        newArray[0] = arr[0];
        return newArray;
    }
    else if(size == 2){
        int* newArray = new int[size];
        if(arr[0] < arr[1]){
            newArray[0] = arr[0];
            newArray[1] = arr[1];
        }
        else{
            newArray[0] = arr[1];
            newArray[1] = arr[0];
        }
        return newArray;
    }

    // recursive cases
    int halfIndex = size / 2;
    int* sortedLeft = mergeSort(arr, halfIndex);
    int* sortedRight = mergeSort(arr + halfIndex, size - halfIndex);
    int* merged = MergeInOrder(sortedLeft, halfIndex, sortedRight, size - halfIndex);

    if(sortedLeft != nullptr){
        delete [] sortedLeft;
        sortedLeft = nullptr;
    }
    if(sortedRight != nullptr){
        delete [] sortedRight;
        sortedRight = nullptr;
    }
 
    return merged;
}

int main(){
    srand(time(NULL));
    int size = 5;
    int* arr = nullptr;
    newArray(arr, size);
    printArray(arr, size,size);

    auto start = steady_clock::now();
    int* newArr = mergeSort(arr,size);
    auto stop = steady_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);

    cout << endl << endl ;
    printArray(newArr, size,size);
    cout << endl << "Time: " << duration.count() << endl;

    if(arr != nullptr){
        delete [] arr;
        arr = nullptr;
    }

    if(newArr != nullptr){
        delete [] newArr;
        newArr = nullptr;
    }

    cout << endl << endl << count;
    return 0;
}